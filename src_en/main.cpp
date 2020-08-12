#define GREEN std::cout << "\033[32;1m"
#define PURPLE std::cout << "\033[35;1m"
#define RESET std::cout << "\033[0m"

#include <iostream>
#include "randomizer.h"
#include "move.h"
#include "key_detect.h"

#define MIN 0
#define MAX 16
#define VERT 4
#define HORIZ 4

using namespace std;



struct field {
    int game_field[VERT][HORIZ];
    int* field_ = (int*)game_field;
};



class game_start {
protected:
    field _field;
    shtick _shtick;
    randomizer<int> symbol_int;

public:
    game_start() {
        symbol_int.set_begin((int)'A');
        symbol_int.set_end((int)'O');
        _shtick.sh_vert = VERT - 1;
        _shtick.sh_hori = HORIZ - 1;
    }

    ~game_start() {}
};



class game_field_initialize : public game_start {
public:
    void field_fill() {
        int temp;
        bool is_present;

        for (int j = MIN; j < (MAX - 1); j++) {
            if (j == MIN) {
                temp = symbol_int.get_randome_element();
                _field.field_[j] = temp;
            }

            if (j > MIN) {
                do {
                    is_present = false;
                    temp = symbol_int.get_randome_element();

                    for (int i = MIN; i < j; i++) {
                        if (temp == _field.field_[i]) is_present = true;
                    }

                } while (is_present == true);

                _field.field_[j] = temp;
            }
        }

        _field.field_[MAX - 1] = (int)'*';
    }

    ~game_field_initialize() {}
};



class checking : public game_field_initialize {
public:
    bool field_final_check() {
        bool is_found = false;
        bool find_compare;
        int _count = 0;

        for (int i = MIN; i < (MAX - 2); i++) {
            find_compare = ((_field.field_[i] - _field.field_[i + 1]) == -1);

            if (find_compare)
                ++_count;
        }

        if (_count == (MAX - 2))
            is_found = true;

        return is_found;
    }

    ~checking() {}
};



class game_show_field : public checking {
public:
    void field_show() {
        for(int i = 0; i < VERT; i++) {
            for (int j = 0; j < HORIZ; j++) {
                cout << (char)_field.game_field[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void game_error() {
        cout << "Key error!" << endl;
        system("echo '\007'");
        exit(-1);
    }

    void hat_show() {
        cout << "===================== GAME 15 =====================" << endl;
        cout << "<ESC> exit | <F1> restart | <up down left right>" << endl;
        cout << "===================================================" << endl << endl;
    }

    void score_show(int temp) {cout << endl << "Step - " << temp << endl;}
    void winner() {cout << "You win!" << endl;}
    ~game_show_field() {}
};



class gaming : public game_show_field {
public:
    void swap_shtick(int vert, int horiz) {
        shtick _new;

        _new.sh_vert = _shtick.sh_vert + vert;
        _new.sh_hori = _shtick.sh_hori + horiz;

        bool is_error = (_new.sh_vert == 4 || _new.sh_vert < 0 || _new.sh_hori == 4 || _new.sh_hori < 0);
        if (is_error)
            game_error();

        swap(_field.game_field[_shtick.sh_vert][_shtick.sh_hori], _field.game_field[_new.sh_vert][_new.sh_hori]);

        _shtick.sh_vert = _new.sh_vert;
        _shtick.sh_hori = _new.sh_hori;
    }

    ~gaming() {}
};



void running_game();


//======================================================================
int main() {
    running_game();

    return 0;
}
//======================================================================


void running_game() {
    key_detect _key_detect;
    movment _movment;
    gaming _gaming;

    bool escape_key;
    bool restart_game;
    bool error_key;
    bool final_check;

    _gaming.field_fill();

    int steps = 0;

    for (;;) {
        system("clear");
        _gaming.hat_show();
        PURPLE;
        _gaming.field_show();
        _gaming.score_show(steps);
        RESET;

        _key_detect.put_symbol();
        _key_detect.key_detection();


        error_key = (_key_detect.get_key_name() == "no button found...");
        escape_key = (_key_detect.get_key_name() == "key_esc");
        restart_game = (_key_detect.get_key_name() == "key_f1");

        if (error_key) {
            _gaming.game_error();
        }

        else {
            if (escape_key)
                exit(0);

            if (restart_game)
                running_game();

            _gaming.swap_shtick(_movment.e_motion(_key_detect.get_key_name())->moove().sh_vert, _movment.e_motion(_key_detect.get_key_name())->moove().sh_hori);
        }

        final_check = (_gaming.field_final_check() == true);

        if (final_check) {
            break;
        }

        ++steps;
    }

    system("echo '\007'");
    system("clear");
    GREEN;
    _gaming.field_show();
    _gaming.winner();
    _gaming.score_show(steps);
    RESET;
    cin.get();
    system("clear");
}
