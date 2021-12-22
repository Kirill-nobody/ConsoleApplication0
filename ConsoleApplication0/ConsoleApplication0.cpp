#include <stdio.h>
#include <string.h>

//удаляет слова с большим количеством букв, чем задано
void deleteWordsWithMoreLetters(char text[], int count) {
	int lettersCount = 0, counter = 0;
	char answer[150];
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] != ' ' && text[i] != '\n') {
			lettersCount++;
		}
		else if(text[i] == ' ' || (text[i] == '\n' && i == strlen(text) - 1)){
			if (lettersCount <= count) {
				for (int j = i - lettersCount; j < i; j++) {
					answer[counter] = text[j];
					counter++;
				}
				answer[counter] = ' ';
				counter++;
			}
			lettersCount = 0;
		}
	}
	answer[counter] = '\0';
	printf("%s\n", answer);
}

//ставит большие буквы в начале каждого слова
void bigLetterInBeginWords(char text[]) {
	for (int i = 0; i < strlen(text); i++) {
		if ((((int)text[i] > 96 && (int)text[i] < 123) || ((int)text[i] > 223 && (int)text[i] < 256)) && (text[i - 3] == ' ' || i == 0)) {
			text[i] = (char)((int)text[i] - 32);
		}
	}
	printf("%s\n", text);
}

//меняет регистр букв НА ВЫБРАННОМ УЧАСТКЕ
void changeCase(char text[]/*, int start, int stop*/) {
	//if (start >= 0 && stop < strlen(text))
	{
		for (char i = 0; i <= strlen(text); i++)
		{
			if (((int)text[i] > 96 && (int)text[i] < 123) || ((int)text[i] > 223 && (int)text[i] < 256))
			{
				text[i] = (char)((int)text[i] - 32);
			}
			else if (((int)text[i] > 159 && (int)text[i] < 192) || ((int)text[i] > 64 && (int)text[i] < 91))
			{
				text[i] = (char)((int)text[i] + 32);
			}
		}
		printf("%s", text);
	}
//	else
{
printf("The entered sequence goes beyond the bounds of the array. Please enter a sequence from 0 to %d", strlen(text));
}
}

int main(void) {
	char ch[150];
	printf("Please, write text: ");
	fgets(ch, 150, stdin);
	fflush(stdin);
	printf("Result of deleteSentensesWithMoreWords method job: ");
	deleteWordsWithMoreLetters(ch, 5);
	printf("Please, write text: ");
	fgets(ch, 150, stdin);
	fflush(stdin);
	printf("Result of bigLetterInBeginWords method job: ");
	bigLetterInBeginWords(ch);
	printf("Please, write text: ");
	fgets(ch, 150, stdin);
	fflush(stdin);
	printf("Result of changeCase method job: ");
	changeCase(ch/*, 3, 6*/);
}
