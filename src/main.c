//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : main.c                                                        //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// GBDK
#include <gb/gb.h>
// Game
#include "../include/types.h"
#include "../include/screens.h"


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
init_game()
{
    disable_interrupts();
    DISPLAY_OFF;

    SPRITES_8x8;

    SHOW_BKG;
    SHOW_SPRITES;

    DISPLAY_ON;
    enable_interrupts();
}


//----------------------------------------------------------------------------//
// Entry Point                                                                //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
main()
{
    init_game();
    change_screen_to(SCREEN_TYPE_SPLASH);

    while(TRUE) {
        BOOL s = (*screen_run_func)();
        if(s == FALSE) {
            screen_end_func();
        }
        wait_vbl_done();
    }

    printf("FODA_SE");
}
