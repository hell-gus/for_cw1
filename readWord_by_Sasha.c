Word readWord(){
    Word word;
    word.len = 0;
    word.chars = (wchar_t*) malloc(sizeof(wchar_t));

    wchar_t symbol;
    do{
        symbol = (wchar_t) getwchar();
    } while (symbol == L' ');

    while(true){
        if (symbol==L'\n') newlineCounter++;
        else newlineCounter=0;
        if (newlineCounter==2) break;
        
        if ((symbol == L' ') || (symbol == L'.') || (symbol == L',') || (symbol == L'\n') || (symbol == WEOF)){
            word.sep = symbol;
            word.chars[word.len] = L'\0';
            break;
        }
        word.chars[word.len++] = symbol;
        word.chars = (wchar_t*) realloc(word.chars, sizeof(wchar_t) * (word.len + 1));
        symbol = (wchar_t) getwchar();
    }

    return word;
}
