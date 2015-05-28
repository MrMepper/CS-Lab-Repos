#pragma once
class WordGame
{
 private:
    char* fileName;
    char* word;
    
  public:
    WordGame();
    ~WordGame();
    char* getFileName();
    void setFileName(char* fn);
    void setWord(int rand_no);
    char* getWord();
    void draw();  
	int play();
};

