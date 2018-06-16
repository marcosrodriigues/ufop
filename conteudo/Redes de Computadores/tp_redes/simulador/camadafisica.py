# -*- coding: utf-8 -*-
"""
    File name: camadafisica.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 5/30/2017
    Data last modified: 3/08/2017
    Python version: 2.7
    License: GPL
"""

import socket
import random
from threading import Thread
from datetime import datetime


class CamadaFisica(object):
    """
    Simulação da camada física, responsável por controlar as mensagens
    """

    def __init__(self, transporte, host, porta, use_5b_encode, prob_inversao):
        """
        Função init da classe
        :param transporte(string): Tipo da camada TCP ou UDP
        :param host(string): Endereço de IP para subir ou conectar ao servidor 
        :param porta(int): Porta
        :param use_5b_encode(bool): True caso for usar codificacao 4b/5b
        :param prob_inversao(float): probabilidade de um bit ser transmitido com erro
        :return None
        """
        self.__transporte = transporte
        self.__host = host
        self.__porta = porta
        tipo_socket = {'UDP': socket.SOCK_DGRAM, 'TCP': socket.SOCK_STREAM}
        self.__socket = socket.socket(socket.AF_INET, tipo_socket[transporte])
        # self.__socket.settimeout(2)

        self.__map_4b = {'0000': '11110', '0001': '01001', '0010': '10100', '0011': '10101', '0100': '01010',
                         '0101': '01011', '0110': '01110', '0111': '01111', '1000': '10010', '1001': '10011',
                         '1010': '10110', '1011': '10111', '1100': '11010', '1101': '11011', '1110': '11100',
                         '1111': '11101'}
        self.__map_5b = {
            '11110': '0000',
            '01001': '0001',
            '10100': '0010',
            '10101': '0011',
            '01010': '0100',
            '01011': '0101',
            '01110': '0110',
            '01111': '0111',
            '10010': '1000',
            '10011': '1001',
            '10110': '1010',
            '10111': '1011',
            '11010': '1100',
            '11011': '1101',
            '11100': '1110',
            '11101': '1111'
        }
        self.__use_5b_encode = use_5b_encode
        self.__prob_inversao = prob_inversao

    def servir(self):
        """
        Mantem a camada servindo, funcionando como um servidor
        :return: None
        """
        self.__socket.bind((self.__host, self.__porta))

        # if self.__transporte == 'TCP':
        #     self.__socket.listen(1)
        #     return self.__servir_tcp()
        #
        # return self.__servir_udp()

    def receber(self, ack=False):
        """
        Receber uma mensagem
        :return:
        """

        return self.__receber_msg_udp(ack)

    def __receber_msg_tcp(self, conexao, cliente):
        """
        Trata mensagens recebidas através do protocolo TCP
        :param conexao(Connection): Objeto da conexao
        :param cliente(tuple): Identificação do cliente 
        :return: None
        """
        while True:
            msg = conexao.recv(1024)
            if not msg:
                break
                # print("[Servidor][{}] {} - {} - [{}]".format(datetime.now(), cliente, msg, len(msg)))
        conexao.close()

    def __servir_tcp(self):
        """
        Trata os clientes TCPs conectados ao servidor, instanciando uma thread pra cada cliente
        :return: None
        """
        threads = []
        while True:
            conexao, cliente = self.__socket.accept()
            thread = Thread(target=self.__receber_msg_tcp, args=(conexao, cliente))
            thread.start()
            threads.append(thread)

    def __servir_udp(self):
        """
        Trata os clientes UDPs conectados ao servidor
        :return: None
        """
        while True:
            self.__receber_msg_udp()

    def __receber_msg_udp(self, ack=False):
        """
        Trata a mensagem enviado por um cliente UDP
        :return: None
        """
        # msg, cliente = self.__socket.recvfrom(1024)
        # print("[Servidor][{}] {} - {} - [{}]".format(datetime.now(), cliente, msg, len(msg)))

        try:
            msg, cliente = self.__socket.recvfrom(1024)
            msg = msg.decode('utf-8')
            if self.__use_5b_encode and not ack:
                msg = self.__convert_to_4b(msg)
                print(msg)
            return msg, cliente
        except:
            return None, None

    def __enviar_tcp(self, msg):
        """
        Envia uma mensagem utilizando o protocolo TCP
        :param msg(string): Mensagem para ser enviada
        :return: None
        """
        self.__socket.send(msg)

    def __enviar_udp(self, msg, cliente):
        """
        Envia uma mensagem utilizando o protocolo UDP
        :param: msg(string): Mensagem para ser enviado
        :param cliente(tuple): Caso seja um servidor, direcionar a mensagem para o cliente correto
        :return: None
        """
        if cliente is None:
            self.__socket.sendto(msg, (self.__host, self.__porta))
        else:
            self.__socket.sendto(msg, cliente)

    def __convert_to_5b(self, msg):
        """
        Converte mensagem em padrao 4b para padrao 5b
        Caso a mensagem não tenha tamanho multiplo de 4, então são adicionados 0 ao final da mensagem
        :param: msg(string): Mensagem para converter
        :return: Mensagem convertida
        """

        # adiciona 0 ao fim da mensagem
        if len(msg) % 4 != 0:
            msg = msg + ('0' * (4 - (len(msg) % 4)))

        new = ""
        for i in range(0, len(msg), 4):
            new += self.__map_4b[msg[i:i + 4]]

        return new

    def __aplica_erro_inversao(self, msg):
        """
        Aplica na mensagem a probabilidade de erro de transmissao 
        :param msg: mensagem onde pode ocorrer o erro
        :return: nova mensagem, com erro
        """
        msg = list(msg)
        for i in range(len(msg)):
            rand = random.uniform(0, 1)
            if rand < self.__prob_inversao:
                msg[i] = ('1', '0')[int(msg[i])]

        msg = ''.join(msg)
        return msg

    def enviar_msg(self, msg, cliente=None, ack=False):
        """
        Trata uma mensagem a ser enviada, direcionando ao protocolo certo
        :param cliente: Caso seja um servidor, devolve a mensagem para o cliente
        :param msg: Mensagem a ser enviada
        :return: None
        """
        # print("[Cliente][{}] - {} - [{}]".format(datetime.now(), msg, len(msg)))

        if self.__use_5b_encode and not ack:
            msg = self.__convert_to_5b(msg)
        # msg = self.__aplica_erro_inversao(msg)

        # if self.__transporte == 'TCP':
        #     return self.__enviar_tcp(msg)
        # print(msg)

        return self.__enviar_udp(msg.encode('utf-8'), cliente)

    def __convert_to_4b(self, msg):
        out = ''
        for i in range(0, len(msg), 5):
            out += self.__map_5b[msg[i:i+5]]
        print(out)
        return out
