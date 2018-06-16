# -*- coding: utf-8 -*-
import json


class ConfigurationFile(object):
    def __init__(self):
        self.__config = json.load(open('config.json'))

    def get_network(self):
        return self.__config['network']


class Configuration(object):
    options = ConfigurationFile()
