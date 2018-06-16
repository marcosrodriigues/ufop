# -*- coding: utf-8 -*-
"""
    File name: roteador.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 08/23/2017
    Data last modified: 08/23/2017
    Python version: 3
    License: GPL
"""

from threading import Thread

import json
from time import sleep

from simulador import CamadaEnlace, CamadaFisica, CamadaTransporte


class RoteadorConsumer(Thread):
    def __init__(self, porta):
        print('porta {}'.format(porta))
        self.__pacotes = []
        self.__transporte = CamadaTransporte()
        self.__fisica = CamadaFisica('UDP', '0.0.0.0', porta, False, 0)
        self.__receiving_lock = False

        Thread.__init__(self)

    def coletar_pacotes(self):
        while self.__receiving_lock:
            pass
        pacotes = self.__pacotes
        self.__pacotes = []
        return pacotes

    def run(self):
        while True:
            msg, cliente = self.__fisica.receber(ack=True)
            print(msg)
            if msg == 'REPASS':
                msg, cliente = self.__fisica.receber()
                print(msg)
                while msg != 'DONE':
                    self.__receiving_lock = True
                    source, target, foo = self.__transporte.desenpacotar_mensagem(msg)
                    self.__pacotes.append({'msg': msg, 'target': target})
                    msg, cliente = self.__fisica.receber()
                self.__receiving_lock = False


class Roteador(Thread):
    def __init__(self, porta):
        self.__consumes = RoteadorConsumer(porta)
        self.__enlace = CamadaEnlace(0.1, 0.01, 0.01, 32, (10, 20))
        self.__transporte = CamadaTransporte()
        self.__conexoes = {}
        self.__conexoes_router = {}

        self.__fila_pacotes = []

        self.__killme = False

        Thread.__init__(self)
        self.__consumes.start()

    def adicionar_conexao(self, conexao_ip, conexao_porta, endereco):
        self.__conexoes[endereco] = CamadaFisica('UDP', conexao_ip, conexao_porta, False, 0)

    def adicionar_conexao_router(self, conexao_ip, conexao_porta, endereco):
        self.__conexoes_router[endereco] = CamadaFisica('UDP', conexao_ip, conexao_porta, False, 0)

    def killme(self):
        self.__killme = True

    def run(self):
        while not self.__killme:
            for conexao in self.__conexoes.values():
                # print('Enviando send')
                conexao.enviar_msg('SEND', ack=True)
                # print('Esperando resposta')
                msg, cliente = conexao.receber()
                # print(msg)
                if msg != '':
                    checksum = self.__enlace.verifica_check_sum([int(i) for i in msg])
                    while not checksum:
                        print('error')
                        conexao.enviar_msg('SEND_AGAIN', ack=True)
                        msg, cliente = conexao.receber()
                        if msg == '':
                            break
                        checksum = self.__enlace.verifica_check_sum([int(i) for i in msg])
                    conexao.enviar_msg('OK')
                    try:
                        source, target, foo = self.__transporte.desenpacotar_mensagem(msg)
                        pacote = {'msg': msg, 'target': target}
                        self.__fila_pacotes.append(pacote)
                    except:
                        pass
            for pacote in self.__fila_pacotes:
                if pacote['target'] in self.__conexoes:
                    conexao = self.__conexoes[pacote['target']]
                    # print('Enviando recv')
                    conexao.enviar_msg('RECV', ack=True)
                    # print('Enviando msg')
                    conexao.enviar_msg(pacote['msg'])
                elif pacote['target'].split('.')[0] in self.__conexoes_router:
                    print(self.__conexoes_router)
                    print('not {}'.format(pacote['target']))
                    conexao = self.__conexoes_router[pacote['target'].split('.')[0]]

                    conexao.enviar_msg('REPASS', ack=True)
                    conexao.enviar_msg(pacote['msg'])
                    conexao.enviar_msg('DONE')

            for pacote in self.__consumes.coletar_pacotes():
                if pacote['target'] in self.__conexoes:
                    print('yes {}'.format(pacote['target']))
                    conexao = self.__conexoes[pacote['target']]
                    # print('Enviando recv')
                    conexao.enviar_msg('RECV', ack=True)
                    # print('Enviando msg')
                    conexao.enviar_msg(pacote['msg'])
                elif pacote['target'].split('.')[0] in self.__conexoes_router:

                    conexao = self.__conexoes_router[pacote['target'].split('.')[0]]
                    conexao.enviar_msg('REPASS', ack=True)
                    conexao.enviar_msg(pacote['msg'])
                    conexao.enviar_msg('DONE')

            self.__fila_pacotes = []
        print('morri router')
