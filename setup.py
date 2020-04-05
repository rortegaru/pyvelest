from setuptools import setup, Extension
from Cython.Distutils import build_ext
import numpy as np

NAME = "stom"
VERSION = "0.1"
DESCR = "This is a wrapper of the computer programs of seismology to import in python"
URL = "http://www.google.com"
REQUIRES = ['numpy', 'cython']

AUTHOR = "Roberto Ortega"
EMAIL = "ortegarobe@gmail.com"

LICENSE = "Apache 2.0"

SRC_DIR = "stom"
PACKAGES = [SRC_DIR]

ext_1 = Extension(SRC_DIR + ".velest",
                  [SRC_DIR + "/fbufopen.c", SRC_DIR + 
                   "/velest.pyx",SRC_DIR+"/c_velest.c"],
                  libraries=["velest","gfortran","m"],
                  include_dirs=[np.get_include()],
                  library_dirs=[SRC_DIR],
                  extra_compile_args=["-O2","-Wno-absolute-value","-Wno-shift-op-parentheses","-Wno-logical-op-parentheses"])
#ext_2 = Extension(SRC_DIR + ".c_func",
#                  [SRC_DIR + "/fbufopen.c", SRC_DIR + "/velesm.c",SRC_DIR + 
#                   "/c_func.c",SRC_DIR+"/c_velest.c"],
#                  libraries=["f2c","m"],
#                  include_dirs=[np.get_include()],
#                  extra_compile_args=["-Wno-absolute-value","-Wno-shift-op-parentheses","-Wno-logical-op-parentheses"])



EXTENSIONS = [ext_1]

if __name__ == "__main__":
    setup(install_requires=REQUIRES,
          packages=PACKAGES,
          zip_safe=False,
          name=NAME,
          version=VERSION,
          description=DESCR,
          author=AUTHOR,
          author_email=EMAIL,
          url=URL,
          license=LICENSE,
          cmdclass={"build_ext": build_ext},
          ext_modules=EXTENSIONS
          )
