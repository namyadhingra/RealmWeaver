from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext
import pybind11

# List of minigames with C++ files
minigame_modules = [
    Pybind11Extension(
        "g1_memoryCardMatching",  # Module name
        ["C:\\Namya\\DSAProject\\src\\Minigames\\g1_memoryCardMatching.cpp"],  # Source file for this minigame
    ),
    Pybind11Extension(
        "g2_treasureHuntMaze",
        ["C:\\Namya\\DSAProject\\src\\Minigames\\g2_treasureHuntMaze.cpp"],
    ),
    Pybind11Extension(
        "g3_wordScramble",
        ["C:\\Namya\\DSAProject\\src\\Minigames\\g3_wordScramble.cpp"],
    ),
    # Will need to add other minigames similarly
]

# Setup configuration
setup(
    name="MinigamesPackage",
    version="1.0",
    description="Minigames for the 2D Game Project",
    ext_modules=minigame_modules,
    cmdclass={"build_ext": build_ext},
    include_dirs=[pybind11.get_include()],  # This line includes the path to pybind11 headers
)
