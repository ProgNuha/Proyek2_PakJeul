#include "includes/general.h"
#include "includes/46_Kiki_Pratiwi.h"
#include "includes/65_Velia_Sagita_P.h"
#include "includes/50_Mufida_Nuha_S.h"
#include "includes/03_Ananda_K.h"
#include "includes/54_Nikita_Nabila.h"

int main(int argc, char** argv) {
    initwindow(WIDTH,HEIGHT,"",MARGIN_LEFT, MARGIN_RIGHT);
//	splash_screen();
//    PlaySound("sounds/opening.wav",NULL,SND_ASYNC | SND_LOOP);
//	main_menu();		//tampilan menu awal berisi pilihan menu yang menuju ke UI lain sesuai button yang dikli
	set_goal_and_level();

	getch();
    closegraph();
    
	return 0;
}
