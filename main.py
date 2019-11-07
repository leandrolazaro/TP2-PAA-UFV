import os
from csvGenerators import *

def showMenu():
    print("---------------------------------------------------------")
    print("          TP2 de Projeto de Análise de Algoritmos        ")
    print("---------------------------------------------------------")
    print("1 - Executar algorítmos manualmente;")
    print("2 - Criar pirâmide de entrada;")
    print("3 - Executar testes exaustivos para exibir gráficos;")
    print("4 - Exibir gráficos;")
    print()
    print("9 - Sair.")
    print("---------------------------------------------------------")
    print()

def showAlgorithms():
    print("---------------------------------------------------------")
    print("                  Escolha um algorítmo                   ")
    print("---------------------------------------------------------")
    print("1- Problema da pirâmide recursivo;")
    print("2- Problema da pirâmide com memorization;")
    print("3- Problema da pirâmide de trás para frente;")
    print("4- Problema da distância de edição;")
    print()
    print("8- Ligar/desligar modo debug")
    print("9- Voltar.")
    print("---------------------------------------------------------")
    print()

pyramidExecutable = "cd pyramidProblem && ./pyramidProblem.o"
distanceExecutable = "cd editionDistanceProblem && ./editionDistanceProblem.o"

debug = True

pyramidFiles = "pyramidProblem/inputFiles/"

print("Compilando binários...")
os.system("cd pyramidProblem && make")
os.system("cd editionDistanceProblem && make")
print()

showMenu()

while True:


    while True:
        try:
            selection = int(input("Digite uma entrada ou 0 para reexibir o menu: "))
            break
        except:
            print("Digite um valor inteiro!")

    if(selection==0):
        showMenu()

    elif(selection==1):
        showAlgorithms()

        while True:
            try:
                subSelection = int(input("Digite uma entrada: "))
                break
            except:
                print("Erro! Digite um valor inteiro!")

        if(subSelection==1 or subSelection==2 or subSelection==3):

            while True:
                try:
                    filename = input("Digite o nome do arquivo. Ele deve estar em pyramidProblem/inputFiles: ")
                    fileInput = open(pyramidFiles + filename)
                    break
                except:
                    print("Erro! Arquivo inexistente!")

            os.system(pyramidExecutable + " " + str(subSelection-1) + " " + filename + " 1")

        elif(subSelection==4):

            firstWord = input("Digite a primeira palavra: ")
            secondWord = input("Digite a segunda palavra: ")

            os.system(distanceExecutable + " " + firstWord + " " + secondWord + " 1")
        
        elif(subSelection==9):
            pass

        else:
            print("Opção inválida! Voltando ao menu principal...")

    elif(selection==9):
        break

    else:
        print("Opção inválida!")