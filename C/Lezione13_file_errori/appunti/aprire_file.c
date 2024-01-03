#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    // Apriamo in scrittura, appendendo, creando il file se non esite
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
    
    char contents[13] = "Hello World\n";
    
    write(fd, contents, 12);
    
    close(fd);
    
    return 0;
}