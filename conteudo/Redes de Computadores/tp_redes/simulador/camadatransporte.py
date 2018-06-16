# -*- coding: utf-8 -*-
"""
    File name: camadatransporte.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 8/09/2017
    Data last modified: 8/09/2017
    Python version: 2.7
    License: GPL
"""


class CamadaTransporte(object):
    """
    Simulacao da Camada de Transporte
    """

    def __init__(self):
        mensagem = []

    def gerar_pacote(self, origem, destino, mensagem):
        mensagem_ascii = map(ord, mensagem) # converter mensagem para ASCII
        mensagem_binario = ''.join(['{0:08b}'.format(c) for c in mensagem_ascii]) # converter mensagem para binario
        pacote = '{0:08b}'.format(int(destino.split('.')[0])) + '{0:08b}'.format(int(destino.split('.')[1])) + mensagem_binario
        pacote = '{0:08b}'.format(int(origem.split('.')[0])) + '{0:08b}'.format(int(origem.split('.')[1])) + pacote
        return pacote

    def desenpacotar_mensagem(self, pacote):
        origem = '{}.{}'.format(int(pacote[:8], 2), int(pacote[8:16], 2))
        destino = '{}.{}'.format(int(pacote[16:24], 2), int(pacote[24:32], 2))
        msg = pacote[32:-6]
        return origem, destino, ''.join([chr(int(msg[i:i + 8], 2)) for i in range(0, len(msg), 8)])

    def enviar(self, pacote):
        """
        Encapsula a mensagem recebida pela camada de aplicação em segmentos
        
        pacote["ip"]: string contendo ip
        pacote["porta"]: string contendo a porta
        pacote["mensagem"]: string contendo a mensagem a ser enviada
        :param pacote: Mensagem recebida da camada de aplicacao 
        :return: mensagem encapsulada para camada de rede
        """

        mensagem = []

        pacote['ip'] = pacote['ip'].split('.') # separa a string de acordo com o .
        mensagem += list(''.join(format(int(x), 'b').zfill(8) for x in pacote['ip'])) # converte string em binario

        mensagem += list(format(int(pacote['porta']), 'b').zfill(40)) # converte o numero da porta em binario

        # caso seja necessario particionar os pacotes
        if len(pacote['mensagem']) > 256:
            # TODO: necessario particionar o pacote
            mensagem += list(''.join(format(ord(p), 'b').zfill(8) for p in pacote['mensagem']))

        else:
            mensagem += list(''.join(format(ord(p), 'b').zfill(8) for p in pacote['mensagem']))

        return mensagem
