import sys
import os
import datetime
import subprocess
import shutil

sys.path.append('project/build')
import run



backup_folder = "backups"
hddbackup_folder = "c:\\Shawn\\projects\\GP32\\backups"
zip_path = "\"c:\\program files\\7-Zip\\7z.exe\""

def create_backup_folders():
    if not os.path.exists(backup_folder):
        if os.makedirs(backup_folder):
            raise Exception("Error encountered while trying to create backups folder")
    if not os.path.exists(hddbackup_folder):
        if os.makedirs(hddbackup_folder):
            raise Exception("Error encountered while trying to create hdd backups folder")

def zip_project_to_backup_folder():
    run.configure_project_name()

    time = datetime.datetime.now()
    destination_zipfile = "{0}\\{1}-{2}-{3}.zip".format(backup_folder, run.PROJECT_NAME, time.date(), datetime.datetime.strftime(time, "%Hh%Mm%Ss"))


    command_line = "{0} a -tzip {1} project\ -xr!*.sdf -xr!*.elf -xr!*.o -xr!*.opensdf -xr!ipch -xr!.vs -xr!.git -xr!Release -xr!Debug -xr!gale2c.pch -xr!*.pdb -xr!*.pyc -xr!*.user -xr!*.db -xr!*.iobj -xr!*.ipdb".format(zip_path, destination_zipfile)

    print command_line
	
    if subprocess.call(command_line):
    #if os.system(command_line):
        raise Exception("Error encountered running command line: " + command_line)

    shutil.copy(destination_zipfile, hddbackup_folder)
    
def main():
   
    create_backup_folders()
    zip_project_to_backup_folder()


if __name__ == "__main__":
    sys.exit(main())


