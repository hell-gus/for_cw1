void setOfLetters(Text* text, wchar_t* str){
    for(int i = 0; i < text->len; i++){
        for(int j = 0; j < text->sents[i].len; j++){
            bool flag = false;
            for(int h = 0; h < text->sents[i].words[j].len; h++){
                if(wcschr(str, towlower(text->sents[i].words[j].chars[h])) == NULL){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                wprintf(L"%ls\n", text->sents[i].words[j].chars);
            }
        }
    }
}
