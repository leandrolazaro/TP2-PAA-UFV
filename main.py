import os
from csvGenerators import *

print("Compilando binários...")
os.system("cd pyramidProblem && make")
os.system("cd editionDistanceProblem && make")