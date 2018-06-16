#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
    File name: main.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 5/30/2017
    Data last modified: 6/12/2017
    Python version: 2.7
    License: GPL
"""

from simulador import CamadaFisica
from simulador import CamadaEnlace
from simulador import Configuration
from simulador import HostConsumer, Roteador
from simulador import CamadaTransporte
from simulador import CamadaAplicacao

from threading import Thread
from time import sleep


# class Servidor(Thread):
#     """
#     Thread para simular um servidor
#     """
#     def __init__(self, tipo, porta):
#         Thread.__init__(self)
#         self.__camadafisica = CamadaFisica(tipo, '127.0.0.1', porta, False, 0.01)
#
#     def run(self):
#         self.__camadafisica.servir()
#
#
# class Cliente(Thread):
#     """
#     Thread para simular um cliente
#     """
#     def __init__(self, tipo, endereco, porta):
#         Thread.__init__(self)
#         self.__camadafisica = CamadaFisica(tipo, endereco, porta, False, 0.01)
#         self.__camadaenlace = CamadaEnlace(0.1, 0.01, 0.01, 32, (10, 20))
#
#     def run(self):
#         while True:
#             frame = self.__camadaenlace.gerar_frame()
#             frame = self.__camadaenlace.aplicar_ruido(frame)
#             frame = self.__camadaenlace.gera_check_sum(frame)
#             msg = ''.join([str(bit) for bit in frame])
#             self.__camadafisica.enviar_msg(msg)
#             sleep(0.5)
#
#
# if __name__ == '__main__':
#     thread_servidor = Servidor('UDP', 6666)
#     thread_cliente = Cliente('UDP', '127.0.0.1', 6666)
#
#     thread_servidor.start()
#     thread_cliente.start()
#
#     thread_cliente.join()
#     thread_servidor.join()
from simulador.cliente import Cliente
from simulador.servidor import Servidor


class Manager(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.__hosts = {}
        self.__routers = []
        self.__enlace = CamadaEnlace(0.1, 0.01, 0.01, 32, (10, 20))
        self.__transporte = CamadaTransporte()

        self.load_network()

    def load_network(self):
        network = Configuration.options.get_network()
        for host in network['hosts']:
            if 'type' in host:
                self.__hosts[host['name']] = Servidor(host['name'], host['address'], host['port'])
            else:
                self.__hosts[host['name']] = Cliente(host['name'], host['address'], host['port'], host['server'], host['script'])
            self.__hosts[host['name']].start()

        for router in network['routers']:
            r = Roteador(router['port'])
            for connection in router['connections']:
                r.adicionar_conexao('127.0.0.1', self.__hosts[connection].get_porta(),
                                    self.__hosts[connection].get_endereco())
            for router_connection in dict(router['routers']).items():
                r.adicionar_conexao_router('127.0.0.1', router_connection[1], router_connection[0])
            r.start()
            self.__routers.append(r)

    def run(self):
        pass

if __name__ == '__main__':
    manager = Manager()
    manager.start()

    manager.join()
