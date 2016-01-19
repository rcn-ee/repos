#! /usr/bin/env python
#

from deb822 import Deb822
import re

gOldVersion = None
gNewVersion = None


class BoostVersion:
    def __init__(self, version):
        (self.Major,self.Minor,self.Revision) = version.split('.')
        self.PackageVersion = self.Major + '.' + self.Minor
        self.SharedObjectVersion = version
    def containsPackageVersion(self, string):
        '''Return true if 'string' contains the Package version string.'''
        return re.search(self.PackageVersion, string) is not None
    def containsSharedObjectVersion(self, string):
        '''Return true if 'string' contains the Shared Object version string.'''
        return re.search(self.SharedObjectVersion, string) is not None
    def stripVersion(self, string):
        '''Remove PackageVersion or SharedObjectVersion if contained in 'string'.'''
        return self.replaceVersion(string,'')
    def replaceVersion(self, string, replacement):
        '''Replace either PackageVersion or SharedObjectVersion if contained in 'string',
        with 'replacement'.'''
        string = re.sub(self.SharedObjectVersion, replacement, string)
        string = re.sub(self.PackageVersion, replacement, string)
        return string

def replaceVersion(string, ver1, ver2):
    '''Search 'string' for a BoostVersion ver1.  If
    SharedObjectVersion or PackageVersion of ver1 is found, replace by
    corresponding ver2 version string.  Return the updated string.'''
    string = re.sub(ver1.SharedObjectVersion, ver2.SharedObjectVersion, string)
    string = re.sub(ver1.PackageVersion, ver2.PackageVersion, string)
    return string

def updateVersionedValue(paragraph, key):
    if not paragraph.has_key(key): return
    oldValue = paragraph[key]
    paragraph[key] = replaceVersion(paragraph[key], gOldVersion, gNewVersion)
    return (oldValue, paragraph[key])

def conflictsWithPrevious(paragraph):
    if not paragraph.has_key('Conflicts'): return False
    nameRe = re.sub('\d', '\\d', paragraph['Package'])
    return re.search(nameRe, paragraph['Conflicts']) is not None

def updateConflicts(paragraph, oldPkgName):
    newPkgName = paragraph['Package']
    needsConflict = (newPkgName.endswith("-dev") and not newPkgName.endswith("-all-dev")) or conflictsWithPrevious(paragraph)
    if not needsConflict: return
    if paragraph.has_key('Conflicts'):
        if paragraph['Conflicts'].find(oldPkgName) == -1:
            paragraph['Conflicts'] += ', ' + oldPkgName
    else:
        paragraph['Conflicts'] = oldPkgName

def processSourceParagraph(p):
    updateVersionedValue(p, 'Source')

def processPackageParagraph(p):
    (oldPkgName, newPkgName) = updateVersionedValue(p, 'Package')
    updateVersionedValue(p, 'Depends')
    updateVersionedValue(p, 'Recommends')
    updateVersionedValue(p, 'Suggests')
    updateConflicts(p, oldPkgName)

def printParagraph(p):
    for key in p.keys():
        print "%s: %s" % (key, p[key])

def processControl():
    firstParagraph = True
    for paragraph in Deb822.iter_paragraphs(open('control.in')):
        if firstParagraph:
            processSourceParagraph(paragraph)
            printParagraph(paragraph)
            firstParagraph = False
        else:
            processPackageParagraph(paragraph)
            print
            printParagraph(paragraph)



gOldVersion = BoostVersion('1.54.0')
gNewVersion = BoostVersion('1.55.0')
processControl()
