/* Точка входа в код ядра */
ENTRY (init)

SECTIONS
{
/* Адрес, с которого будет начинаться код ядра в памяти */
    . = 0x00100000;
/* Секция кода */

    .text ALIGN (0x1000) :
    {
        *(.mboot)
        *(.text)
    }
/* Секция инициализированных данных */
    .data ALIGN (0x1000) :
    {
        *(.data)
    }
/* Секция неинициализированных данных */    
    .bss :
    {
        *(.bss)
    }
/* Место в памяти, где уже нет кода ядра */
    end = .; _end = .; __end = .;  
}