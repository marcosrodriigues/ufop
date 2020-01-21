import numpy as np
from scipy.optimize import fsolve

#Primeira regra de simpson: F é a função; A e B os intervalos superiores e inferiores.
def simps(f,a,b,N=50):
    # Deve ser par para respeitar a regra de simpson
    if N % 2 == 1:
        raise ValueError("N must be an even integer.")

    # Dividimos o intervalo [A, B] em subintervalos de tamanho N
    dx = (b-a)/N

    # Geramos (N+1) intervalos de A até B
    x = np.linspace(a,b,N+1)
    # Calculando o valor de 'y' pra cada x gerado na funcao F (oferta ou demanda)
    y = f(x)
    
    '''
        Calculando a regra de simpson
            y[0:-1:2] começa no 0, vai até [n-1] de 2 em 2
            y[1::2] começa no 1, até o fim, de 2 em 2
            y[2::2] começa no 2, ate o fim, de 2 em 2
    '''

    S = dx/3 * np.sum(y[0:-1:2] + 4*y[1::2] + y[2::2])
    
    return S

# Excedente de demanda
def cons_surplus(pe,qe,Dq):
    #cs = [integral] [0, qe] (Dq) - peqe
    cs = simps(Dq,0,qe,10) - pe*qe
    return cs

# Excedente de oferta
def prod_surplus(pe,qe,Sq):
    #cs = peqe - [integral] [0, qe] (Dq)
    ps = pe*qe - simps(Sq,0, qe, 10)
    return ps

def surplus(Sq, Dq):
    # definindo y = sq-dq (quantidade de oferta - quantidade de demanda)
    y = lambda q: Sq(q) - Dq(q)

    x0 = 1
    ''' 
        Calculando a quantidade equilibrada a ser produzida
        Basicamente se faz Sq = Dq e acha a raiz positiva
     '''
    qe = fsolve(y, x0)

    # calcula o preço equilibrado de acordo com a quantidade equilibrada
    pe = Sq(qe)

    #calculo a integral que retorna o excedente do consumidor
    cs = cons_surplus(pe,qe,Dq)
    #calculando a integral que retorna o excedente de oferta
    ps = prod_surplus(pe,qe,Sq)
    
    #Recomenda-se produzir Qe produtos e vender a Pe preco
    print ('Equilibrio de mercado encontrado em [pe;qe] = [', pe , qe ,']')
    print ('Excedente de oferta (economia do produtor) igual a: ' , np.round(ps,2))
    print ('Excedente do consumidor (economia do consumidor) igual a: ' , np.round(cs, 2))

'''
    Exemplo de teste:
        Função de demanda: D(q) = 20 / (q+1)
        Função de oferta: S(q) = q + 2

        Função de demanda: D(q) = (30 + q) / (q**2 + 1)
        Função de oferta: S(q) = q**2 + 1

        Função de demanda: D(q) = (20 + q) / (4q + 1)
        Função de oferta: S(q) = q^3 + 1
'''

sq = lambda q: q + 2
dq = lambda q: 20 / (q + 1)
print("Executando (1)")
surplus(sq, dq)


sq = lambda q: q**2 + 1
dq = lambda q: (30 + q) / (q**2 + 1)
print("Executando (2)")
surplus(sq, dq)

sq = lambda q: q**3 + 1
dq = lambda q: (20 + q) / (4*q + 1)
print("Executando (3)")
surplus(sq, dq)