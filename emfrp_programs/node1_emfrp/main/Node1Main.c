#include "Node1.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

void Input(int* gpio16) {
  *gpio16 = gpio_get_level(16);
}
void Output(int* gpio17) {
  /* Your code goes here... */
  gpio_set_level(17, *gpio17);
}
#if 0
void interruption(void * arg) {
  ExecNode1();
}
int app_main() {
  printf("Emfrp NODE1\n");
  gpio_config_t g = {0};
  g.intr_type = GPIO_INTR_DISABLE;
  g.mode = GPIO_MODE_OUTPUT;
  g.pin_bit_mask = 1ULL << 17; // GPIO17
  g.pull_down_en = 0;
  g.pull_up_en = 0;
  gpio_config(&g);
  g.intr_type = GPIO_INTR_ANYEDGE;
  g.pin_bit_mask = 1ULL << 16; // GPIO16
  g.mode = GPIO_MODE_INPUT;
  gpio_config(&g);
  gpio_install_isr_service(0);
  gpio_isr_handler_add(16, interruption, NULL);
  InitNode1();
  while(1){ vTaskDelay(100000); }
}
#else
int app_main() {
  printf("Emfrp NODE1\n");
  gpio_config_t g = {0};
  g.intr_type = GPIO_INTR_DISABLE;
  g.mode = GPIO_MODE_OUTPUT;
  g.pin_bit_mask = 1ULL << 17; // GPIO17
  g.pull_down_en = 0;
  g.pull_up_en = 0;
  gpio_config(&g);
  g.intr_type = GPIO_INTR_DISABLE;
  g.pin_bit_mask = 1ULL << 16; // GPIO16
  g.mode = GPIO_MODE_INPUT;
  gpio_config(&g);
  InitNode1();
  while (1) {
    int ch = fgetc(stdin);
    if(ch == 'a') {
      printf("10 times Heap free size: %ld\n", esp_get_free_heap_size());
      for(int i = 0; i < 10; ++i) {
        ExecNode1();
      }
      printf("10 times Heap free size: %ld\n", esp_get_free_heap_size());
      break;
    } else if(ch == 'b') {
      printf("100 times Heap free size: %ld\n", esp_get_free_heap_size());
      for(int i = 0; i < 100; ++i) {
        ExecNode1();
      }
      printf("100 times Heap free size: %ld\n", esp_get_free_heap_size());
      break;
    }
  }
  while(1){ vTaskDelay(100000); }
  return 0;
}
#endif
