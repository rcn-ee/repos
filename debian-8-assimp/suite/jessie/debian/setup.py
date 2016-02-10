from distutils.core import setup

setup_data = dict(packages=['pyassimp', ],
                  package_dir = {'pyassimp': 'port/PyAssimp/pyassimp'},
                  name='PyAssimp',
                  version='3.0.1264',
                  author='ASSIMP Development Team',
                  author_email='https://sourceforge.net/mailarchive/forum.php?forum_name=assimp-discussions',
                  license='BSD (3-clause)',
                  url='http://assimp.sf.net',
                  description='Wrapper for ASSIMP at '
                              'http://assimp.sourceforge.net',
                  long_description='''\
A wrapper for the Open Asset Import Library (ASSIMP).'''
                  )

if __name__ == '__main__':
    setup(**setup_data)
