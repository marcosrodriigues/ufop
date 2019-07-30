from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('cat=<int:pk>', views.search_by_cat, name='index_cat'),
    path('vinho/<int:pk>', views.detail_index, name='vinho_detail'),
    path('carrinho', views.carrinho, name='carrinho'),
    path('carrinho/add', views.carrinho_add, name="carrinho_add"),
    path('carrinho/remover', views.carrinho_remove, name='carrinho_remove'),
    path('checkout', views.checkout, name='checkout')
]
