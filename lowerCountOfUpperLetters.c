void lowerCountOfUpperLetters(Text* text){
    int count = 0;
    int g;    
    int remember = 1;
    bool flag = false;
    for(int i = 0; i < text->len; i++){
        for(int j = 0; j < text->sents[i].len; j++){
            for(int h = 0; h <text->sents[i].words[j].len; h++){
                if(i==0){
                    if(iswupper(text->sents[i].words[j].chars[h])){
                        //wprintf(L"meow-%lc\n", text->sents[0].words[j].chars[h]);
                        count++;
                        //wprintf(L"%d\n", count);
                    }    
                } else{
                    //wprintf(L"gav-%lc\n", text->sents[i].words[j].chars[h]);
                    if(remember == i){
                        if(iswupper(text->sents[i].words[j].chars[h])){
                            g++;
                            if(g > count){
                                flag = true;
                            }
                        }
                    } else {
                        g = 0;
                        remember = i;
                    }
                }                   
            }
        }
        if(flag == true){
            removeSentence(i, text);
        }
    }
    
}
