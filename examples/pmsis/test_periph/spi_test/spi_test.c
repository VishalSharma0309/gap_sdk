#include "stdio.h"

/* PMSIS includes. */
#include "pmsis.h"

/* Variables used. */
char hello[16];

void spi_test (void){
    printf("Entering main controller\n");

    uint32_t errors = 0;
    
    struct pi_device spi;
    
    struct pi_spi_conf conf; 
    /*  int max_baudrate;
        char wordsize;
        char big_endian;
        pi_spi_polarity_e polarity; -> polarity of the clock
        pi_spi_phase_e phase;
        
        signed char cs; ->Specifies which SPI chip select is used for the device

        signed char itf; -> specifies on which SPI interface the device is connected

        int max_rcv_chunk_size;
        int max_snd_chunk_size;
    */

    // Initiating SPI with default settings
    pi_spi_conf_init(&conf);
    // conf is a pointer to the SPI master configuration.

    // making changes to the default settings
    conf.wordsize = 16;
    conf.max_baudrate = 115200;

    // opening SPI
    errors = pi_spi_open (&spi);

    if (errors == -1){
        printf("SPI open failed !\n");
        pmsis_exit(-1);
    }

    //uint32_t core_id = pi_core_id(), cluster_id = pi_cluster_id();
    //sprintf(hello, "[%d %d] Hello World !\n", cluster_id, core_id);
    //hello = "hey";
    sprintf(hello, "Hello World !");

    /* Write though uart. */
    #if (ASYNC)
    pi_task_t wait_task = {0};
    pi_task_block(&wait_task);
    pi_spi_send_async(&spi, hello, strlen(hello), 0, &wait_task); // 0 used in place of flags to enable default values
    pi_task_wait_on(&wait_task);
    #else
    pi_spi_send(&spi, hello, strlen(hello), 0);
    #endif

    pi_uart_close(&spi);

    pmsis_exit(errors);

}

/* Program Entry. */
int main(void)
{

    printf("\n\n\t *** PMSIS SPI HelloWorld ***\n\n");
    return pmsis_kickoff((void *) spi_test);
}