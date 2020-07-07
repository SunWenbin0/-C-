#include <stdio.h>
#include <math.h>
#include <ctype.h>
int Determine_letter_position(char X)//判断字母的位置
{
    int Y=0;
    switch(X)
    {
        case 'A':Y=1;break;
        case 'a':Y=1;break;
        case 'B':Y=2;break;
        case 'b':Y=2;break;
        case 'C':Y=3;break;
        case 'c':Y=3;break;
        case 'D':Y=4;break;
        case 'd':Y=4;break;
        case 'E':Y=5;break;
        case 'e':Y=5;break;
        case 'F':Y=6;break;
        case 'f':Y=6;break;
        case 'G':Y=7;break;
        case 'g':Y=7;break;
        case 'H':Y=8;break;
        case 'h':Y=8;break;
        case 'I':Y=9;break;
        case 'i':Y=9;break;
        case 'J':Y=10;break;
        case 'j':Y=10;break;
        case 'K':Y=11;break;
        case 'k':Y=11;break;
        case 'L':Y=12;break;
        case 'l':Y=12;break;
        case 'M':Y=13;break;
        case 'm':Y=13;break;
        case 'N':Y=14;break;
        case 'n':Y=14;break;
        case 'O':Y=15;break;
        case 'o':Y=15;break;
        case 'P':Y=16;break;
        case 'p':Y=16;break;
        case 'Q':Y=17;break;
        case 'q':Y=17;break;
        case 'R':Y=18;break;
        case 'r':Y=18;break;
        case 'S':Y=19;break;
        case 's':Y=19;break;
        case 'T':Y=20;break;
        case 't':Y=20;break;
        case 'U':Y=21;break;
        case 'u':Y=21;break;
        case 'V':Y=22;break;
        case 'v':Y=22;break;
        case 'W':Y=23;break;
        case 'w':Y=23;break;
        case 'X':Y=24;break;
        case 'x':Y=24;break;
        case 'Y':Y=25;break;
        case 'y':Y=25;break;
        case 'Z':Y=26;break;
        case 'z':Y=26;break;
    }
    return Y;
}
void Judgment_component(char a[][10])//判断输入的成分
{
    int b=0;
    while(a[0][b] != '\0')
    {
        if ((a[0][b] >= 'A' && a[0][b] <= 'Z') || (a[0][b] >= 'a' && a[0][b] <= 'z'))
        {
            a[1][0]++;//字母
        }
        else if (a[0][b] >= '0' && a[0][b] <= '9')
        {
            a[1][1]++;//数字
        }
        else
        {
            a[1][2]++;//其他
        }
        b++;
    }
}
int main()
{
    char Array_of_inputs[2][10]={0, 0};
    /*
     数字和字母的混合
     字母的数量，数字的数量，其他的数量
     */
    int Position_of_numbers=0;//数字的位置
    char Array_of_output_numbers[20]={0};//输出数字的数组
    int Final_digital_output_array[20]={0};//最终的数字输出数组
    int The_cycle_of_judging_numbers=0;//判断数字的循环
    int Judging_the_circulation_of_letters_1=0;//判断字母的循环_1
    int Judging_the_circulation_of_letters_2=0;//判断字母的循环_2
    int Number_for_conversion_to_base=0;//转化进制用的数
    char Array_of_output_letters[20]={0};//输出字母的数组
    gets_s(Array_of_inputs[0],10);
    Judgment_component(Array_of_inputs);
    printf("字母数： ");
    for(int b=0;Array_of_inputs[0][b] != '\0';b++)
    {
        printf("%c", Array_of_inputs[1][b]);
    }
    printf("\n");
    printf("数字数： ");
    for(int c=0;Array_of_inputs[1][c] != '\0';c++)
    {
        printf("%c", Array_of_inputs[1][c]);
        printf("    ");
    }
    printf("\n");
    if(Array_of_inputs[1][2]!=0)
    {
        printf("这程序不是用来给你玩的！\n");
    }
    else
    {
        for(int b=0;Array_of_inputs[0][b] != '\0';b++)
        {
            if ((Array_of_inputs[0][b] >= 'A' && Array_of_inputs[0][b] <= 'Z') || (Array_of_inputs[0][b] >= 'a' && Array_of_inputs[0][b] <= 'z'))//字母
            {
                Judging_the_circulation_of_letters_1=b;
                while(islower(Array_of_inputs[0][Judging_the_circulation_of_letters_1]) == 0 || isupper(Array_of_inputs[0][Judging_the_circulation_of_letters_1]) == 0)//判断不是字母
                {
                    Judging_the_circulation_of_letters_1++;
                    Number_for_conversion_to_base++;
                }
                if(Judging_the_circulation_of_letters_2==0)
                {
                    Array_of_output_letters[b]=Determine_letter_position(Array_of_inputs[0][b])* (int)pow(26,Number_for_conversion_to_base-1);
                    Judging_the_circulation_of_letters_2=1;
                }
                else
                {
                    Array_of_output_letters[b]=Array_of_output_letters[b]+Determine_letter_position(Array_of_inputs[0][b])*(int)pow(26,Number_for_conversion_to_base-1);
                }
                Number_for_conversion_to_base=0;
                Position_of_numbers++;
                The_cycle_of_judging_numbers=0;
            }
            else if (Array_of_inputs[0][b] >= '0' && Array_of_inputs[0][b]<= '9')//数字
            {
                if(The_cycle_of_judging_numbers==0)
                {
                    Array_of_output_numbers[Position_of_numbers]=Array_of_inputs[0][b];
                    The_cycle_of_judging_numbers=1;
                }
                else
                {
                    Array_of_output_numbers[Position_of_numbers]=Array_of_output_numbers[Position_of_numbers]*10+Array_of_inputs[0][b];
                }
                Judging_the_circulation_of_letters_2=0;
            }
            else
            {
                printf("出错！\n");
                Position_of_numbers++;
                The_cycle_of_judging_numbers=0;
                Judging_the_circulation_of_letters_2=0;
            }
        }
        for (int a = 0; Array_of_output_numbers[a] != '\0'; a++)//char数组转化成int数组
        {
            Final_digital_output_array[a] = (int)Array_of_output_numbers[a] - 48;
        }
        printf("字母为：\n");
        for(int c=0;Array_of_output_letters[c] != '\0';c++)
        {
            printf("%c",Array_of_output_letters[c]);
        }
        printf("数字为：\n");
        for(int d=0;Array_of_output_numbers[d] != '\0';d++)
        {
            printf("%d", Final_digital_output_array[d]);
        }
    }
    return 0;
}