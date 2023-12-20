#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>

/* Il programma parallel_max.c legge il contenuto di un file in
modo binario, lo interpreta come un array di numeri interi, e
stampa il numero più alto tra quelli letti.
Il calcolo del numero più alto avviene in parallelo su due
thread the operano su due diverse metà dell’array. */

// Struttura per contenere i dati da processare
struct data_t
{
  int *data;
  size_t len;
};

// Funzione per leggere i numeri interi da un file
struct data_t read_nums(FILE *file);

// Funzione per trovare il massimo tra gli elementi di un array
int max_in_data(int *data, size_t len);

// Funzione eseguita dai thread per calcolare il massimo nei loro dati
void *compute_max(void *ptr);

int main(int argc, char **argv)
{
  // Controllo degli argomenti in ingresso
  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s file_name num_threads\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "rb"); // Apre il file in modalità di lettura binaria
  if (!file)
  {
    perror("fopen()");
    return 2;
  }

  int num_threads = atoi(argv[2]); // Numero di thread da creare

  struct data_t data = read_nums(file); // Legge i numeri interi dal file
  printf("Letti %zu numeri interi.\n", data.len);

  pthread_t threads[num_threads]; // Array di thread
  struct data_t thread_data[num_threads]; // Array di strutture dati per i thread

  // Calcola la dimensione del lavoro di ogni thread
  size_t chunk_size = data.len / num_threads;

  // Assegna porzioni di dati a ciascun thread
  for (int i = 0; i < num_threads; ++i)
  {
    // Imposta la lunghezza dei dati per ciascun thread
    thread_data[i].len = (i == num_threads - 1) ? (data.len - chunk_size * (num_threads - 1)) : chunk_size;
    // Imposta il puntatore ai dati per ciascun thread
    thread_data[i].data = data.data + (i * chunk_size);

    // Crea un thread per ogni porzione di dati
    pthread_create(&threads[i], NULL, compute_max, &thread_data[i]);
  }

  int max = INT_MIN; // Variabile per il massimo globale

  // Calcola il massimo tra i valori restituiti dai singoli thread
  for (int i = 0; i < num_threads; ++i)
  {
    void *result_ptr;
    pthread_join(threads[i], &result_ptr); // Attende il completamento di ciascun thread

    int result = *(int *)result_ptr; // Estrae il risultato dal thread
    max = (result > max) ? result : max; // Aggiorna il massimo globale
    free(result_ptr); // Libera la memoria allocata per il risultato
  }

  // Stampa il massimo numero trovato
  printf("Il massimo numero trovato è %d\n", max);

  free(data.data); // Libera la memoria dei dati letti dal file
  fclose(file); // Chiude il file

  return 0;
}

// Resto delle funzioni rimane invariato...

// Funzione eseguita dai thread per trovare il massimo all'interno dei dati assegnati
void *compute_max(void *ptr)
{
  struct data_t data = *(struct data_t *)ptr;

  int *result = malloc(sizeof(int)); // Alloca memoria per il risultato
  *result = max_in_data(data.data, data.len); // Trova il massimo tra i dati

  return result; // Restituisce il risultato
}

// Trova il massimo all'interno di un array di interi
int max_in_data(int *data, size_t len)
{
  int max = INT_MIN;
  for (int i = 0; i < len; ++i)
  {
    if (data[i] > max)
      max = data[i];
  }
  return max;
}

#define NITEMS 2000 // Numero di elementi per blocco di lettura
// Legge i numeri interi dal file
struct data_t read_nums(FILE *file)
{
  size_t size = NITEMS;
  struct data_t data = {
      .len = 0,
      .data = malloc(sizeof(int) * size)}; // Alloca memoria per i dati

  int r = 0;
  while ((r = fread(data.data + data.len, sizeof(int), NITEMS, file)) == NITEMS)
  {
    data.len += r; // Aggiorna la lunghezza dei dati letti
    size += NITEMS; // Aggiorna la dimensione
    data.data = realloc(data.data, sizeof(int) * size); // Realloca la memoria per contenere più dati
  }

  return data; // Restituisce la struttura dati
}