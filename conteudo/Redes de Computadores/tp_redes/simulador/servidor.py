# -*- coding: utf-8 -*-
"""
    File name: servidor.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 08/23/2017
    Data last modified: 08/23/2017
    Python version: 3
    License: GPL
"""
import json
from threading import Thread

from simulador import CamadaAplicacao


class Servidor(Thread):
    def __init__(self, nome, endereco, porta):
        self.__aplicacao = CamadaAplicacao(nome, endereco, porta, [])
        self.__status = {}
        self.__killme = False
        Thread.__init__(self)

    def get_porta(self):
        return self.__aplicacao.get_porta()

    def get_endereco(self):
        return self.__aplicacao.get_endereco()

    def run(self):
        while not self.__killme:
            pacotes = self.__aplicacao.coletar_pacotes()
            for origem, destino, mensagem in pacotes:
                requisicao = json.loads(mensagem)
                if requisicao['code'] == 'LOGIN':
                    self.__status[origem] = 'online'
                    self.__aplicacao.enviar_pacote(origem, json.dumps({'status': 200, 'data': 'LOGIN_SUCCESS'}))
                elif requisicao['code'] == 'LOGOUT':
                    self.__status[origem] = 'offline'
                    self.__aplicacao.enviar_pacote(origem, json.dumps({'status': 200, 'data': 'LOGOUT_SUCCESS'}))
                elif requisicao['code'] == 'GET_ONLINE':
                    online = [u[0] for u in self.__status.items() if u[1] == 'online']
                    self.__aplicacao.enviar_pacote(origem, json.dumps({'status': 200, 'data': {'online': online}}))
                else:
                    self.__aplicacao.enviar_pacote(origem, json.dumps({'status': 400}))


