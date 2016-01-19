#! /usr/bin/python

import os, re, sys
from subprocess import call, check_call

def extract_tar(tarfile,rootdir):
    """Extract files from a tar archive.

    Arguments:
    tarfile -- file name of tar archive
    rootdir -- directory into which the archive is extracted

    """
    cmd = ["tar","--extract"]

    if tarfile.endswith(".gz"):
        cmd.append("--gzip")
    elif tarfile.endswith(".bz2"):
        cmd.append("--bzip")

    cmd.append("--file")
    cmd.append(os.path.abspath(tarfile))

    check_call(cmd, cwd=rootdir)


def wget_localhost_files(serverbase,tempdir):
    """Use wget to obtain files from localhost server.

    server -- root of file tree on http://localhost
    tempdir -- directory into which the files are placed

    """
    cmd = ["wget", "--quiet",
           "--recursive", "--no-parent",
           "--domains=localhost",
           "http://localhost/" + serverbase]
    retcode = call(cmd, cwd=tempdir)
    if not(retcode == 0 or retcode == 8):
        raise RuntimeError("wget failed")

def find_file_root(dirname,filename):
    """Recursively search the dir for a file."""
    while 1:
        #print "Considering " + dirname
        if not os.path.isdir(dirname): return None
        files = os.listdir(dirname)
        if len(files) == 1:
            dirname = os.path.abspath(os.path.join(dirname,files[0]))
        else:
            if filename in files:
                return dirname
            return None

def list_doc_files(rootdir,src_rootdir):
    """List files comprising the Boost documentation tree.

    Returns list of filenames, relative to given rootdir, that
    make up the Boost documentation.  This is all files that:
      (a) are not in subdir $rootdir/boost AND
      (b) endswith .html or .htm OR
          is a file in $src_rootdir
    
    """
    doc_files = []
    for dirpath, dirs, files in os.walk(rootdir):
        if dirpath == rootdir:
            dirs.remove("boost")
        for filename in files:
            #print "Considering: ", filename
            filepath = os.path.abspath(os.path.join(dirpath,filename))
            filepath = filepath.replace(rootdir,"",1)
            if filepath.startswith("/"):
                filepath = filepath[1:]
            keep = filename.endswith(".html") or \
                   filename.endswith(".htm") or \
                   os.path.exists(os.path.join(src_rootdir,filename))
            if keep:
                doc_files.append(filepath)
                #print filepath
                
    return doc_files


def main():
    if (len(sys.argv) != 3):
        print "Usage: %s tarfile boost_x_y_z" % sys.argv[0]
        return 1
    tarfile, path = sys.argv[1:3]
    tar_extract_root = "/home/steve/public_html"
    url_root = "~steve/" + path + "/index.html"
    
    extract_tar(tarfile, tar_extract_root)
    wget_localhost_files(url_root, "/tmp")
    boost_dir = find_file_root("/tmp/localhost", "boost")
    files = list_doc_files(boost_dir,
                           os.path.join(tar_extract_root,path))
    files.sort()
    for f in files:
        print f

main()
