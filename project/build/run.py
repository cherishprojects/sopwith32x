import argparse
import datetime
import time
from glob import glob
import os
import shutil
import subprocess
import sys
import shutil

MAKEFILE_FILENAME = "makefile"
SCRIPT_PATH = os.path.dirname(os.path.realpath(__file__))
SOURCE_PATH = os.path.normpath(SCRIPT_PATH + '\\..\\src')
PROJECT_PATH = os.path.normpath(SCRIPT_PATH + '\\..')
PROJECT_NAME = ""
MARSDEV_PATH = r"C:\msys64\usr\bin;C:\msys64\mingw64\bin"
MAKE_PATH = r"C:\msys64\usr\bin\make.exe"

returncode = 0
errormessage = ""

def configure_project_name():
    global PROJECT_NAME
    projectname = SCRIPT_PATH.split('\\')[-3]
    PROJECT_NAME = projectname
    print("- Project Name: {0}".format(PROJECT_NAME))


def configure_environment():
    global MARSDEV_PATH
    os.environ["PATH"] = MARSDEV_PATH + ";" + os.environ["PATH"]

def create_folder(path):
    if not os.path.exists(path): 
        os.makedirs(path)

def ensure_folders_created():
    create_folder("out\\src")
    create_folder("out\\src\\32x")

def builddata():
    ensure_folders_created()


def copy_to_daily_versions_folder():
    daily_versions_folder = "..\dailyversions"

    source = "out\\{0}.32x".format(PROJECT_NAME)
    destination = "{0}\\{1}-{2}.32x".format(daily_versions_folder, PROJECT_NAME, datetime.datetime.now().date())
    if not os.path.exists(daily_versions_folder):
        if os.makedirs(daily_versions_folder):
            raise Exception("Error encountered while trying to create Daily Versions folder")

    if os.path.isfile(source):
        print "- Copying backup to Daily Versions folder"
        if shutil.copy(source, destination):
            raise Exception("Error encountered while trying to copy to Daily Versions folder")

def build():

    builddata()

    print("Building rom")
    if os.system(MAKE_PATH + " -f build\\" + MAKEFILE_FILENAME + " MARSDEV=/c/Dropbox/gendev/mars TARGET=" + PROJECT_NAME):
        raise Exception("Error encountered during build")

    copy_to_daily_versions_folder()

    return True


def build_debug():

    builddata()

    print("Building rom")
    if os.system(MAKE_PATH + " debug -f build\\" + MAKEFILE_FILENAME + " MARSDEV=/c/Dropbox/gendev/mars TARGET=" + PROJECT_NAME):
        raise Exception("Error encountered during build")

    copy_to_daily_versions_folder()

    return True

def run():
    filename = "{0}.32x".format(PROJECT_NAME)
    path = os.path.normpath("out\\{0}".format(filename))

    if not os.path.isfile(path):
        raise Exception("File {0} not found".format(path))

    if os.system("start " + path):
        raise Exception("Error trying to run " + path)

def cleancode():
    if os.path.exists("out"):
        print("- Cleaning out folder")

        all_files = os.listdir("out")

        for f in all_files:
            if os.path.isfile("out\\" + f):
                os.remove("out\\" + f)
        all_files = os.listdir("out\\src")

        for f in all_files:
            if os.path.isfile("out\\src\\" + f):
                os.remove("out\\src\\" + f)

def cleanoutfolder():
    if os.path.exists("out"):
        print("- Cleaning out folder")
        shutil.rmtree("out")

def clean():
    cleanoutfolder()

def rebuild():
    clean()
    build()

def rebuildrun():
    rebuild()
    run()

def parse_args():
    parser = argparse.ArgumentParser(description='Marsdev project builder tool')
    subparser = parser.add_subparsers(dest='command')
    run_build = subparser.add_parser('build', help='builds project')
    run_build_debug = subparser.add_parser('build_debug', help='builds project')
    run_builddata = subparser.add_parser('builddata', help='builds project data only')
    run_buildrun = subparser.add_parser('buildrun', help='builds project and runs it')
    run_run = subparser.add_parser('run', help='runs the project')
    run_clean = subparser.add_parser('clean', help='cleans project')
    run_cleancode = subparser.add_parser('cleancode', help='cleans project code objs except generated code')
    run_cleanoutfolder = subparser.add_parser('cleanoutfolder', help='cleans just the out folder of the project')
    run_rebuild = subparser.add_parser('rebuild', help='cleans and builds project')
    run_rebuildrun = subparser.add_parser('rebuildrun', help='cleans, builds and runs project')

    if len(sys.argv) == 1:
        parser.print_help()
        sys.exit(1)
        
    return parser.parse_args()


def hms_string(sec_elapsed):
    h = int(sec_elapsed / (60 * 60))
    m = int((sec_elapsed % (60 * 60)) / 60)
    s = sec_elapsed % 60.
    return "{}:{:>02}:{:>05.2f}".format(h, m, s)

def main():
    global returncode

    print(sys.version)

    os.chdir("..")

    configure_project_name()
    configure_environment()

    # get command line parameters
    args = parse_args()

    print("- Command: {0}".format(args.command))

    # which command?
    if args.command == 'build':
        command = build
    if args.command == 'build_debug':
        command = build_debug
    elif args.command == 'builddata':
        command = builddata
    elif args.command == 'buildrun':
        command = buildrun
    elif args.command == 'run':
        command = run
    elif args.command == 'clean':
        command = clean
    elif args.command == 'cleancode':
        command = cleancode
    elif args.command == 'cleanoutfolder':
        command = cleanoutfolder
    elif args.command == 'rebuild':
        command = rebuild
    elif args.command == 'rebuildrun':
        command = rebuildrun

    # go!
    try:
        startTime = time.time()
        command()
        endTime = time.time()

        print("Elapsed time: " + hms_string(endTime - startTime))


    except Exception as ex:
        print("- {0}".format(ex))
        return 1

if __name__ == "__main__":
    sys.exit(main())
