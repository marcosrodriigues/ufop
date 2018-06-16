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


class Cliente(Thread):
    def __init__(self, nome, endereco, porta, endereco_servidor, script):
        self.__nome = nome
        self.__endereco_servidor = endereco_servidor
        self.__aplicacao = CamadaAplicacao(nome, endereco, porta, [])
        self.__killme = False
        self.__online = False

        self.__pacotes = []
        self.__script = script

        Thread.__init__(self)

    def get_porta(self):
        return self.__aplicacao.get_porta()

    def get_endereco(self):
        return self.__aplicacao.get_endereco()

    def is_online(self, destino):
        self.__aplicacao.enviar_pacote(self.__endereco_servidor, {'code': 'GET_ONLINE'})
        self.__pacotes += self.__aplicacao.coletar_pacotes()
        online = []
        for origem, destino, mensagem in self.__pacotes:
            try:
                response = json.loads(mensagem)
                if response['status'] == 200 and 'data' in response and 'online' in response['data']:
                    online = response['data']['online']
                    self.__pacotes.remove((origem, destino, mensagem))
            except:
                pass
        return online

    def run(self):
        while not self.__online:
            print(self.__endereco_servidor)
            self.__aplicacao.enviar_pacote(self.__endereco_servidor, json.dumps({'code': 'LOGIN'}))
            self.__pacotes += self.__aplicacao.coletar_pacotes()
            for pacote in self.__pacotes:
                origem, destino, mensagem = pacote
                try:
                    response = json.loads(mensagem)
                    if response['status'] == 200 and response['data'] == 'LOGIN_SUCCESS':
                        self.__pacotes.remove((origem, destino, mensagem))
                        self.__online = True
                except:
                    pass

        for message in self.__script:
            if message['action'] == 'recv':
                self.__pacotes += self.__aplicacao.coletar_pacotes()
                for origem, destino, mensagem in self.__pacotes:
                    try:
                        response = json.loads(mensagem)
                        if response['status'] == 200 and 'msg' in response:
                            print('{} - {}'.format(self.__nome, response['msg']))
                            self.__pacotes.remove((origem, destino, mensagem))
                    except:
                        pass

            if message['action'] == 'send':
                self.__aplicacao.enviar_pacote(message['target'], json.dumps({'status': 200, 'msg': message['msg']}))