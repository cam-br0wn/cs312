# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.drum_machine.Debug:
/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/Debug/drum_machine:
	/bin/rm -f /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/Debug/drum_machine


PostBuild.drum_machine.Release:
/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/Release/drum_machine:
	/bin/rm -f /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/Release/drum_machine


PostBuild.drum_machine.MinSizeRel:
/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/MinSizeRel/drum_machine:
	/bin/rm -f /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/MinSizeRel/drum_machine


PostBuild.drum_machine.RelWithDebInfo:
/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/RelWithDebInfo/drum_machine:
	/bin/rm -f /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/hw43/hw431_drumMachine_xcode/build/RelWithDebInfo/drum_machine




# For each target create a dummy ruleso the target does not have to exist
