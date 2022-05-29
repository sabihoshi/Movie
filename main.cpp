#include <iostream>
#include "movielist.h"
#include "console.h"

int menu();

int main()
{
    Blockbuster list;
    list.Load();
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
            case 1:list.addMovie();
                break;
            case 2:list.rentMovie();
                break;
            case 3:list.returnMovie();
                break;
            case 4:list.showMovieDetails();
                break;
            case 5:list.printMovieList();
                break;
            case 6:list.Save();
                list.~Blockbuster();
                return 0;
            default:std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
        std::cout << "Press enter to continue...";
        std::string pause;
        std::getline(std::cin, pause);
    } while (choice != 6);
}

int menu()
{
    system("clear");
    Color lights = {255, 255, 0};
    Color movie = {0, 68, 116};
    Color rent = {45, 200, 255};
    Color number = {255, 255, 0};
    Color input = {146, 208, 80};
    const std::string &light = RGB("•", lights);

    XY(23, 0);
    WriteLine("╔═════════════════════════════════════════════╗");
    WriteLine("║ " + RGB("• • • • • • • • • • • • • • • • • • • • • •", lights) + " ║");
    WriteLine("║ " + light + RGB("╔═╗╔═╦═══╦╗──╔╦══╦═══╗", movie) + RGB("╔═══╦═══╦═╗─╔╦════╗", rent) + light + " ║");
    WriteLine("║ " + light + RGB("║║╚╝║║╔═╗║╚╗╔╝╠╣╠╣╔══╝", movie) + RGB("║╔═╗║╔══╣║╚╗║║╔╗╔╗║", rent) + light + " ║");
    WriteLine("║ " + light + RGB("║╔╗╔╗║║─║╠╗║║╔╝║║║╚══╗", movie) + RGB("║╚═╝║╚══╣╔╗╚╝╠╝║║╚╝", rent) + light + " ║");
    WriteLine("║ " + light + RGB("║║║║║║║─║║║╚╝║─║║║╔══╝", movie) + RGB("║╔╗╔╣╔══╣║╚╗║║─║║  ", rent) + light + " ║");
    WriteLine("║ " + light + RGB("║║║║║║╚═╝║╚╗╔╝╔╣╠╣╚══╗", movie) + RGB("║║║╚╣╚══╣║─║║║─║║  ", rent) + light + " ║");
    WriteLine("║ " + light + RGB("╚╝╚╝╚╩═══╝─╚╝─╚══╩═══╝", movie) + RGB("╚╝╚═╩═══╩╝─╚═╝─╚╝  ", rent) + light + " ║");
    WriteLine("║ " + RGB("• • • • • • • • • • • • • • • • • • • • • •", lights) + " ║");
    WriteLine("║                                             ║");
    WriteLine("║           [" + RGB("1", number) + "] Insert a Movie                ║");
    WriteLine("║           [" + RGB("2", number) + "] Rent a Movie                  ║");
    WriteLine("║           [" + RGB("3", number) + "] Return a Movie                ║");
    WriteLine("║           [" + RGB("4", number) + "] Show Movie Details            ║");
    WriteLine("║           [" + RGB("5", number) + "] Movie List                    ║");
    WriteLine("║           [" + RGB("6", number) + "] Quit                          ║");
    WriteLine("║                                             ║");
    WriteLine("╠═════════════════════════════════════════════╣");
    WriteLine("║                                             ║");
    WriteLine("╚═════════════════════════════════════════════╝");

    XY(24, 19);
    return Prompt<int>(RGB("Enter choice", input));
}