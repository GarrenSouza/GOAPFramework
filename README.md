# GOAPFramework

GOAPFramework is an experimental framework that allows developers to experience some features of the GOAP way to build AI under the Unreal Engine Editor.

## Prerequisites

Before you begin, ensure you have met the following requirements:
* You have installed a version of Unreal Engine that is compatible with projects in Unreal 4.20 (perhaps in the future the project will be upgraded to Unreal 5)
* You have some experience with C++ (pointerrsssss boiiiii, and lots of macros too, so beware)
* You need to have a working install of Visual Studio 2017 at least (it works with VS 2022)
* You have read the [documentation website](https://sites.google.com/view/goap-framework/goap) that walks you through some aspects about how the planner was integrated into the Unreal Engine API (even if you know GOAP inside and out)
* You have some familiarity with the Unreal Engine API (Controllers, Characters, Pawns, Navigation, Life-Cycle, etc)

## Installing/Getting things ready to work

Follow these steps:

Windows:

Right click the ".uproject" file under the project folder and select the option "Generate Visual Studio project files".
Once the work is done (a minute or two) you can launch the ".sln" file (the one with the Visual Studio logo).
You'll notice that the VS will be all over the place parsing tens of thousands of files, everything is fine, you can open the Unreal Editor while VS get the things done.
The core source files are under the very suggestive "Core" folder, just for the record, be very cautious about what you do down there. 

## Using GOAPFramework

To use the features of the framework, at the actual level of development, You need to follow some rules:

Character definition
AIController link
Behavior Trees & Blackboards operations and connections must be bound
* If you want a logger, use StyxLog (built to save your time)

## Contributing to GOAPFramework

I'll make a short guide about contributions, but for now see the GitHub documentation on [creating a pull request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).

## Contact

If you want to contact me you can reach me at <contato.garren@gmail.com>.

## License

This project uses the following license: [GNU General Public License v2.0](<https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html>).
