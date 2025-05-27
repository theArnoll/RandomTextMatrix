#include<cstdio>
#include<random>
#include<ctime>

int main(int argc, char const *argv[]) {
    srand(time(nullptr));
    short chr = 0, type = 1, selectedFont = true;
    if(argc > 1){ chr = atoi(argv[1]);
        if(argc > 2){ type = atoi(argv[2]);
            if(argc > 3) selectedFont = atoi(argv[3]);
            else selectedFont = true; // Default to using the selected font
        } else type = 1; // Default to story
    }
    else
    {
        printf("How many characters?\n > ");
        scanf("%hd", &chr);
        printf("For story or not? (1 for story, 2 for others)\n > ");
        scanf("%hd", &type);
        printf("Using the font \"Major Mono Display\"? (1 for yes, 0 for no)\n > ");
        scanf("%hd", &selectedFont);
        printf("\n");
    }

    for(short block = 0; block < 3; block++) {
        for(short re = 0; re < chr/(block==1?1:type); re++) {
            for(short re2 = 0; re2 < 21; re2++)
                printf("%c", (rand()%26) + ((re2==10 && block==1) ^ !selectedFont ? 'A':'a'));
            printf("\n");
        }
    }
    return 0;
}

// The code below is a commented-out version of the original code

// for(short block = 0; block < 3; block++) {
//         for(short re = 0; re < 7/(block==1 ? 1:1/**/); re++) {
//             for(short re2 = 0; re2 < 21; re2++)
//                 printf("%c", (rand() % 26) + ((re2 == 10 && block == 1) ? 'A' : 'a'));
//             printf("\n");
//         }
// }