#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isUpper(char userInput);
bool isLetter(char userInput);
void printImage(uint64_t Image);


int main(void) {
    uint64_t UpperLetters[] = {
      0xc3c3c3ffff663c18, 0x7fc3c37f7fc3c37f, 0x7c8201010101827c,
      0x3f4181818181413f, 0xffff03ffff03ffff, 0x030303ffff03ffff,
      0x3cc2c1f10181423c, 0x81818181ff818181, 0x7c1010101010107c,
      0x1c1414101010107c, 0x4222120a060a1222, 0xfe02020202020202,
      0x8181818199a5c381, 0x81c1a19189858381, 0x3c4281818181423c,
      0x0202023e4282423e, 0xbc42a1918181423c, 0x4222120a7e42423e,
      0x7c82807e0101423c, 0x080808080808087f, 0x3c42424242424242,
      0x0814224141414141, 0x245a898989818181, 0x8142241818244281,
      0x0808080808142241, 0xff020408102040ff
    };
    uint64_t LowerLetters[] = {
      0x006c322222221c00, 0x1c24241c04040404, 0x003c4202423c0000,
      0x7c22223c20202020, 0x000038043c241800, 0x080808081c082818,
      0x1824203824242418, 0x2424241c04040404, 0x0008080808000800,
      0x0c0a080808000800, 0x24140c1424040404, 0x3048080808080808,
      0x004a4a5a24000000, 0x001212120c000000, 0x1c2222221c000000,
      0x0404041c24241c00, 0x3810101c12121c00, 0x000404040c140000,
      0x003c403c023c0000, 0x001828083e080800, 0x0058242424000000,
      0x1028444444000000, 0x0044aa9191000000, 0x0000241818240000,
      0x0204081028440000, 0x00003c08103c0000
    };
    
    
  char userInput;
  printf("Enter a letter:\n");
  fflush(stdout);
  fflush(stdin);
  scanf("%c",&userInput);
  //Make sure user input a letter
  while(!isLetter(userInput))
  {
      printf("Enter a letter:\n");
      fflush(stdout);
      fflush(stdin);
      scanf("%c",&userInput);
  }
  
    //Get the Image index for the input letter and print the Image
  int ImageIndex;
  uint64_t current;
  if(isUpper(userInput))
  {
      ImageIndex = userInput - 'A';
      current = UpperLetters[ImageIndex];
      printImage(current);
  }
  else
  {
      ImageIndex = userInput - 'a';
      current = LowerLetters[ImageIndex];
      printImage(current);
  }
    return 0;
}


bool isLetter(char userInput)
{
    if((userInput >= 'A' && userInput <= 'Z') || (userInput >= 'a' && userInput <= 'z'))
        return true;
    return false;
}

bool isUpper(char userInput)
{
    if(userInput >= 'A' && userInput <= 'Z')
        return true;
    return false;
}

void printImage(uint64_t Image)
{
    int row = 0;
    int col = 0;
    for (int i = 0; i < 8; i++)
  {
      row = Image & 0xFF;
        Image = Image >> 8;
        for ( int j = 0; j < 8; j++)
        {
            col = row & 0x01;
            row = row >> 1;
          if(col == 1) //0x01 (00000001) = 1 
            printf("*");
          else
            printf(" ");
        }
        printf("\n");
    }
}
