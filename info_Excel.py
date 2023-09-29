import os
import openpyxl

diretorio_pasta = './Outputs'
planilha = openpyxl.Workbook()
planilha_ativa = planilha.active

for nome_arquivo in os.listdir(diretorio_pasta):
    if nome_arquivo.endswith('.txt'):
        caminho_arquivo = os.path.join(diretorio_pasta, nome_arquivo)
        
        with open(caminho_arquivo, 'r') as arquivo_txt:
            linhas = arquivo_txt.readlines()
            
            for linha in linhas:
                planilha_ativa.append([linha.strip()])

planilha.save('informacoes.xlsx')

print('Arquivo Excel criado com sucesso!')
