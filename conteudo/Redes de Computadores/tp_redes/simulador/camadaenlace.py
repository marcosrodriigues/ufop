# -*- coding: utf-8 -*-
"""
    File name: camadaenlace.py
    Author: Ana Moraes, Daniela Pralon, Eduardo Andrews, João Paulo Reis Alvarenga, Manoel Stilpen, Patrick Rosa
    Date created: 5/30/2017
    Data last modified: 3/08/2017
    Python version: 2.7
    License: GPL
"""
from random import random, randint, choice


class CamadaEnlace(object):
    """
    Simulação da Camada de Enlace, responsável por gerar os quadros e gerar os ruídos nas mensagens
    """

    def __init__(self, prob_inversao, prob_adicao, prob_rajada, tamanho_frame, intervalo_rajada):
        """
        Função de Init da classe
        :param prob_inversao(float): Probabilidade de inverter um bit
        :param prob_adicao(float): Probabilidade de adicionar um bit para cada bit do frame
        :param prob_rajada(float): Probabilidade de adicionar uma rajada
        :param tamanho_frame(int): Tamanho do frame
        :param invervalo_rajada(tuple(int,int)): Invervalo de tamanhos da rajada
        :return: None
        """
        #TODO: O tipo de tratamento	de erro	na camada de enlace	deve ser configurável.
        #TODO: Implementar os dois protocolos de janela deslizante.

        self.__prob_inversao = prob_inversao    # probabilidade de inverter um bit
        self.__prob_adicao = prob_adicao        # probabilidade de adicionar um bit
        self.__prob_rajada = prob_rajada        # probabilidade da rajada
        self.__tamanho_frame = tamanho_frame    # tamanho do quadro
        self.__intervalo_rajada = intervalo_rajada

    def __inverter_bit(self, bit):  # inversor de bit
        """
        Inverte o bit caso caia no caso probabilístico
        :param bit(int): Bit a ser invertido 
        :return(int): bit invertido ou não
        """
        if random() <= self.__prob_inversao:
            return int(not bit)
        return bit

    def __adicionar_bit(self, bit):
        """
        Adiciona um bit logo após caso caia no caso probabilístico
        :param bit(int): Bit a ser invertido 
        :return(list[int]): Array contendo o somente o bit original, ou o bit original mais um bit
        """
        if random() <= self.__prob_adicao:
            return [bit, randint(0, 1)]
        return [bit]

    def __aplicar_rajada(self, frame):
        """
        Adiciona uma rajada em uma posição aleatória do frame
        :param frame(list[int]): Quadro o qual será adicionada a rajada
        :return(list[int]): Quadro contendo a rajada ou não 
        """
        if random() <= self.__prob_rajada:
            tamanho_rajada = choice(self.__intervalo_rajada)  # escolhe um tamanho aleatório para a rajada
            rajada = [randint(0, 1) for _ in range(tamanho_rajada)]  # gera o conteúdo da rajada
            posicao_insercao = randint(0,
                                       self.__tamanho_frame - 1)  # escolhe aleatóriamente um lugar para inserir a rajada
            frame_final = frame[:posicao_insercao] + rajada + frame[
                                                              posicao_insercao:]  # concatena a rajada junto ao frame
            return frame_final

        return frame

    def __adicionar_checksum(self, frame, checksum):
        """
        Insere no final do frame, 6 bits correspondentes ao valor checksum recebido
        :param frame(list[int]): frame original
        :param checksum(int): valor inteiro do checksum correspondente ao frame
        :return(list[int]): frame com o checksum adicionado
        """

        frame += [int(bit) for bit in '{:06b}'.format(checksum)]

        return frame

    def __calcula_check_sum(self, frame):
        """
        Calcula o valor do checksum para o frame recebido
        :param frame: 
        :return: retorna o valor checksum do frame
        """
        return sum(frame) % 64 # mod de 2^6

    def gerar_frame(self):
        """
        Gera a mensagem original
        :return(list[int]): Retorna a mensagem original 
        """
        frame = [randint(0, 1) for _ in range(self.__tamanho_frame)]  # gera a mensagem original
        return frame

    def aplicar_ruido(self, frame):
        """
        Aplica os ruídos no frame original de dados
        :param frame(list[int]): Quadro original sem ruídos 
        :return(list[int]): Quadro final com ruídos 
        """
        frame_prob_inversao = [self.__inverter_bit(bit) for bit in frame]  # aplica ruido de inversão
        frame_prob_adiconar = []
        for bit in frame_prob_inversao:
            frame_prob_adiconar += self.__adicionar_bit(bit)  # aplica ruido de adição

        frame_final = self.__aplicar_rajada(frame_prob_adiconar)
        return frame_final

    def gera_check_sum(self, frame):
        """
        Gera o valor checksum para o frame recebido.
        Checksum, neste caso, é a soma dos bits do frame
        :param frame(list[int]): Quadro original sem inserção do checksum 
        :return(list[int]): Quadro final com o checksum 
        """

        soma = self.__calcula_check_sum(frame)

        return self.__adicionar_checksum(frame, soma)

    def verifica_check_sum(self, frame):
        """
        Realiza o teste do checksum, caso os valores sejam iguais, então, a mensagem não possui erros.
        :param frame: frame que se deseja verificar o checksum
        :return: True caso a mensagem não contenha erros
        """

        # pega os 6 ultimos bits da mensagem
        checksum = int(''.join(str(x) for x in (frame[-6:])), 2)

        # calcula o checksum com base na mensagem recebida
        checksum_recebido = self.__calcula_check_sum(frame[:-6])

        # caso o checksum calculado e o checksum retirado do frame sejam iguais, entao, não há erro
        if checksum == checksum_recebido:
            return True

        return False

    def gera_paridade(self, frame):
        """
        Aplica Paridade par no frame, adicionando o bit 0 caso a quantidade de bits 1 seja par
        e adicionando o bit 1 caso a quantidade de bits 1 seja impar
        :param frame: quadro para ser inserido o bit de paridade 
        :return: frame com o bit de paridade inserido
        """

        # verificando se a quantidade de 1 e par ou impar
        n = frame.count(1) % 2
        # adicionando no final do frame 0 ou 1
        frame.append((0, 1)[n])

        return frame

    def verifica_paridade(self, frame):
        """
        Realiza a verificacao de paridade        
        :param frame(list[int]): mensagem para verificar
        :return: True caso a paridade esteja ok
        """

        # pega o ultimo bit do frame, o bit que indica a paridade
        n = frame.count(1) % 2

        if n == 0:
            return True

        return False

    def gera_hamming(self, frame):
        """
        Aplica o código de Hamming no frame recebido
        :param frame: frame que se deseja aplicar o código de hamming
        :return: frame com os bits de hamming inseridos
        """

        n = 0
        pos_verifications_bits = [1]
        while pos_verifications_bits[-1] <= len(frame):
            pos_verifications_bits.append(2 ** len(pos_verifications_bits))

        pos_verifications_bits[:] = [index - 1 for index in pos_verifications_bits]
        print(pos_verifications_bits)

