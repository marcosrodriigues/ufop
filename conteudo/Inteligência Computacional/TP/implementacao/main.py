import numpy as np
from sklearn.neural_network import MLPRegressor
from sklearn.model_selection import train_test_split
from sklearn import metrics

import warnings, time, math

warnings.simplefilter(action="ignore", category=FutureWarning)

def run(count):
	file = 'personality_random_' + str(count) + '.data'
	#file = 'personality.data'

	print("Executando RNA com instancia de " + str(count) + " registros")
	start = time.time()

	# Leitura dos dados utilizando NUMPY
	data = np.genfromtxt(file, dtype=int, delimiter=',')

	# Removendo a primeira linha (header do arquivo)
	data = np.delete(data, 0, 0)

	# Removendo as ultimas colunas (resultado)
	X = np.delete(data, [10, 11, 12, 13, 14, 14], 1)
	# Removendo as primeiras colunas (entrada)
	y = np.delete(data, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 1)

	# Separar o conjunto em treinamento e teste.
	X_train, X_test, Y_train, Y_test = train_test_split(
	    X, y, test_size=0.33, random_state=42
	)

	# Inicialização da rede neural
	mlp = MLPRegressor(hidden_layer_sizes=(100, 100, 100),max_iter=500) 

	mlp.fit(X_train,Y_train) # Substituir pelo conjunto de treinamento
	pred = mlp.predict(X_test)
	print("mean_absolute_error metrics")
	print(metrics.mean_absolute_error(Y_test, pred))

	print("mean squared error")
	print(metrics.mean_squared_error(Y_test, pred))

	print("explained_variance_score")
	print(metrics.explained_variance_score(Y_test, pred))

	print("r2_score")
	print(metrics.r2_score(Y_test, pred))

	end = time.time()
	print("Tempo em segundos: " + str(end - start))
	print("\n")

count = 1000
for i in [1,2,3,4,5]:
	run(count)