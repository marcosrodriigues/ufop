from django.shortcuts import render, redirect
from django.urls import reverse
from django.db.models import Sum
from .models import Vinho, Categoria, Cliente

# Create your views here.
def index(request):
    wines = Vinho.objects.all()
    categorias = Categoria.objects.all()
    search = ''

    if 'search' in request.GET:
        search = request.GET['search']
        wines = Vinho.objects.filter(title__contains=search)

    return render(request, 'vinhos/index.html', { 'vinhos' : wines, 'categorias' : categorias, 'search' : search })

def search_by_cat(request, pk):
    wines = Vinho.objects.filter(categoria_id = pk)
    categorias = Categoria.objects.all()
    search = ''

    if 'search' in request.GET:
        search = request.GET['search']
        wines = wines.filter(title__contains=search)

    return render(request, 'vinhos/index.html', { 'vinhos' : wines, 'categorias' : categorias, 'search' : search })

def detail_index(request, pk):
    wine = Vinho.objects.get(pk=pk)
    clientes = Cliente.objects.all()
    return render (request, 'vinhos/detail.html', { 'vinho' : wine , 'clientes' : clientes})


def carrinho(request):
    clientes = Cliente.objects.all()

    if 'cliente' not in request.POST:
        return render (request, 'vinhos/carrinho.html', {'clientes' : clientes })
    else:
        cliente = Cliente.objects.get(pk=request.POST['cliente'])
        return render (request, 'vinhos/carrinho.html', {'clientes' : clientes, 'cliente' : cliente, 'sum' : cliente.calcularTotalCarrinho() })

    
def carrinho_add(request):
    clientes = Cliente.objects.all()
    vinho = Vinho.objects.get(pk=request.POST['vinho'])
    cliente = Cliente.objects.get(pk=request.POST['cliente'])
    
    cliente.carrinho.add(vinho)
    cliente.save()

    return render(request, 'vinhos/carrinho.html', {'clientes' : clientes, 'cliente' : cliente, 'sum' : cliente.calcularTotalCarrinho() })
    
def carrinho_remove(request):
    if 'cliente' in request.POST:
        cliente = Cliente.objects.get(pk=request.POST['cliente'])
        vinho = Vinho.objects.get(pk=request.POST['vinho'])

        cliente.carrinho.remove(vinho)
        cliente.save()
        return render(request, 'vinhos/carrinho.html', {'clientes': Cliente.objects.all(), 'cliente' : cliente, 'sum': cliente.calcularTotalCarrinho() })
        #return redirect ('/carrinho', {'clientes': Cliente.objects.all(), 'cliente' : cliente })
    
    return render (request, 'vinhos/error.html', { 'error' : 'Vinho ou Cliente não encontrado!'})

def checkout(request):
    if 'cliente' in request.POST:
        cliente = Cliente.objects.get(pk=request.POST['cliente'])

        cliente.carrinho.clear()
        cliente.save()

        return render(request, 'vinhos/checkout.html', { 'cliente' : cliente})