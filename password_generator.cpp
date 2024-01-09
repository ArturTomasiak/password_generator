#include <iostream>
#include <string>
#include <stdlib.h>

int main(){
    std::string special_characters   = "!@#$%^&*()-+";
    std::string numbers              = "0123456789";
    std::string lowercase_letters    = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase_letters    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string password             = "";
    bool        generated            = false;

    int amount_of_special_characters = 5;
    int amount_of_numbers            = 5;
    int amount_of_lowercase_letters  = 5;
    int amount_of_uppercase_letters  = 5;

    srand(time(NULL)); //without this the outcome of rand() would be consistently the same

    while(!generated){
        switch(rand()  % 4){
            case 0:
            if(amount_of_special_characters != 0){
                password += special_characters[rand() % special_characters.length()];
                amount_of_special_characters -= 1;
                break;
            }
            case 1:
            if(amount_of_numbers != 0){
                password += numbers[rand() % numbers.length()];
                amount_of_numbers -= 1;
                break;
            }
            case 2:
            if(amount_of_lowercase_letters != 0){
                password += lowercase_letters[rand() % lowercase_letters.length()];
                amount_of_lowercase_letters -= 1;
                break;
            }
            case 3:
            if(amount_of_uppercase_letters != 0){
                password += uppercase_letters[rand() % uppercase_letters.length()];
                amount_of_uppercase_letters -= 1;
                break;
            }
        }
        if(amount_of_special_characters == 0 && amount_of_numbers == 0 && amount_of_lowercase_letters == 0 && amount_of_uppercase_letters == 0)
            generated = true;
    }

    std::cout << password << "\n";
}