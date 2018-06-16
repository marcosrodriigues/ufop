# -*- coding: utf-8 -*-
"""
    File name: host.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 08/23/2017
    Data last modified: 08/23/2017
    Python version: 3
    License: GPL
"""
import json
from threading import Thread, Lock
from queue import Queue

from simulador import CamadaEnlace, CamadaFisica


class HostConsumer(Thread):
    def __init__(self, porta):
        self.__lock = Lock()
        self.__fisica = CamadaFisica('UDP', '0.0.0.0', porta, False, 0)
        self.__enlace = CamadaEnlace(0.000, 0.0000, 0.000, 32, (10, 20))
        self.__fisica.servir()
        Thread.__init__(self)

        self.__killme = False
        self.__pacote = None

        self.__pacotes_recebidos = []
        self.__pacotes_enviar = []
        self.__ultimo_pacote = None

    def killme(self):
        self.__killme = True

    def send_message(self, packet):
        self.__pacotes_enviar.append(packet)

    def collect_packets(self):
        packets = self.__pacotes_recebidos
        self.__pacotes_recebidos = []
        return packets

    def processar_pacote(self, pacote):
        pacote = self.__enlace.gera_check_sum([int(i) for i in pacote])
        pacote = ''.join(map(str, self.__enlace.aplicar_ruido(pacote)))
        return pacote

    def enviar_pacote(self, pacote, cliente, ack=False):
        if ack:
            self.__fisica.enviar_msg(pacote, cliente)
        else:
            self.__fisica.enviar_msg(self.processar_pacote(pacote), cliente)

    def run(self):
        while not self.__killme:
            # print('Esperando roteador')
            __msg, __cliente = self.__fisica.receber(ack=True)
            # self.__get_shared_values()
            # # print(str(__msg))
            if __msg is None:
                continue
            if __msg == 'SEND_AGAIN':
                if self.__ultimo_pacote is None:
                    self.enviar_pacote('', __cliente)
                else:
                    self.enviar_pacote(self.__ultimo_pacote, __cliente)
                    msg, cliente = self.__fisica.receber(ack=True)
                    while msg != 'OK':
                        self.enviar_pacote(self.__ultimo_pacote, __cliente)
                        msg, cliente = self.__fisica.receber()
                self.__ultimo_pacote = None
            if __msg == 'SEND':  # pergunta ao host se ele tem algo para mandar
                #print('Enviando mensagem com pacotes')
                if len(self.__pacotes_enviar) > 0:
                    self.__ultimo_pacote = self.__pacotes_enviar.pop()
                    self.enviar_pacote(self.__ultimo_pacote, __cliente)
                else:
                    self.enviar_pacote('', __cliente, ack=True)
                # self.__get_shared_values()
                # self.__set_shared_values('')

            if __msg == 'RECV':  # pede ao host para que ele receba um pacote
                # print("Recebendo pacote do roteador")
                msg, cliente = self.__fisica.receber()
                self.__pacotes_recebidos.append(msg)
                # print('Pacote recebido {} - {}'.format(msg_sender, msg))
        print('morri host')


class Host(Thread):
    def __init__(self, porta):
        """
        Inicia o host como servidor que espera o roteador coletar suas mensagens
        :param porta:
        """
        self.__queue = Queue(1)
        self.__pacote = None
        self.__killme = False  # flag para matar host
        self.__thread = HostConsumer(self.__queue, porta)  # Thread para escutar roteador
        self.__porta = porta
        self.__last_message = None
        Thread.__init__(self)
        self.__queue.put({'killme': False, 'pacote': ''})

    def killme(self):
        self.__killme = True

    def get_porta(self):
        return self.__porta

    def send_message(self, target, msg):
        packet = {'target': target, 'msg': msg}
        self.__queue.put({'killme': self.__killme, 'pacote': json.dumps(packet)})

    def run(self):
        self.__thread.start()
        while not self.__killme:
            self.__op = None
            # self.__queue.put({'killme': self.__killme, 'pacote': '{"target": 1, "msg": "olá 1"}'.encode('utf-8')})
