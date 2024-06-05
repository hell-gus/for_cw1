void setOfLetters(Text* text, wchar_t* str){
    int count = 0;
    for(int i = 0; i < text->len; i++){
        bool first_flag = false;
        for(int j = 0; j < text->sents[i].len; j++){
            //bool flag = false;
            for(int h = 0; h < text->sents[i].words[j].len; h++){
                if(wcschr(str, towlower(text->sents[i].words[j].chars[h])) == NULL){
                    //flag = true;
                    count++;
                    break;
                }
            }
            if(count == text->sents[i].words[j].len){
                wprintf(L"99");
            }
        }  
    }
}
