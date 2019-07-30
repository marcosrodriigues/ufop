from django.contrib import admin
from .models import Vinho, Categoria, Cliente

admin.site.register(Vinho)
admin.site.register(Categoria)
admin.site.register(Cliente)