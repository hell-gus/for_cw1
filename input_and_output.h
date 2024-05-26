#include "structs.h"

Word readWord();
Sentence readSentence();
Text readText();
void printText(Text text);
//first formating
int findCopies(Word *word1, Word *word2);
void format(Text *text);
void freeText(Text* text);
void freeSentence(Sentence sent);
void removeSentence (int i, Text* text);
