#include <iostream>
#include <time.h>
#include <algorithm>

const int ship_count = 6; //amount of limited ships in gacha

class _ships{
public:
int ship_rates[ship_count] = {4,4,5,5,10,10}; //droprate of ships. keep total_rate in mind


int breaktrough_rate[ship_count]; // an array that lists when each ship begins and ends its drop on

bool ship_collected[ship_count]; // an array that keeps track of which ships have already been aquired



void reset(){//resets ship_collected array to prepare for next rolling attempt

for(int i = 0; i < ship_count; i++){
    ship_collected[i] = 0;
};

}

void initialize(){//calculates breaktrough rates and sets ships_collected array to 0

int temp = 0;

for(int i = 0; i < ship_count; i++){
    temp += ship_rates[i];
    breaktrough_rate[i] = temp;
};

reset();
};

bool all_gathered_check(){//checks if all targeted ships have already been rolled

for(int i = 0; i < ship_count; i++){
    if(ship_collected[i] == 0) return false;
};

return true;
};

void new_roll(int roll){//checks if new target ships has been rolled
//std::cout << roll << std::endl;
for(int i = 0; i < ship_count; i++){
    if(roll < breaktrough_rate[i]) {
            ship_collected[i] = 1;
            break;}
};

};

} ships;

int main(){

ships.initialize();

srand (time(NULL));

int max_attempt = 100000; //amount of attempts for each roll count. Increasing it should increase precision but will also increase how long it takes to execute the program

int total_rate = 200; // used to set droprate precision. Default 0.5%

int max_roll_count = 300; // maximum amount of rolls it tries to attempt

int min_roll_count = 10; // minimum amount of rolls it tries to attempt

for(int i = min_roll_count; i <= max_roll_count; i++){// loop tries 1 to max_roll_count attempts of rolling

    int successful = 0; //amount of rolls that have been succesful

        for(int attempt = 0; attempt < max_attempt;  attempt++){//each roll count executes max_attempt times

                for(int j = i; j>0; j--){//executes i rolls

                    ships.new_roll(rand() % total_rate);// rolls from 0-(total_rate-1)

                    }

            if(ships.all_gathered_check()) successful++;//checks if all ships have been rolled


            ships.reset(); //resets check values

        }

    std::cout << "If you do " << i << " rolls " << successful << " out of " << max_attempt <<" attempts have succeded" << std::endl;

}

while(true){
system("pause"); //Endless loop just sitting there so you don't accidentaly close the final results
}

}
