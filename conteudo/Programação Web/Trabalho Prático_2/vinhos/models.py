from django.db import models
from django.utils import timezone

class Vinho (models.Model):
    owner = models.ForeignKey('auth.User', on_delete=models.CASCADE)
    title = models.CharField(max_length=200)
    short_description = models.CharField(max_length=75)
    description = models.TextField()
    created_date = models.DateTimeField(default = timezone.now)
    amount = models.IntegerField()
    price = models.FloatField()
    picture = models.ImageField(
        upload_to="vinhos_imagens", verbose_name="Imagem: ", null=False, blank=False
    )
    categoria = models.ForeignKey('Categoria', related_name='vinhos', 
        on_delete=models.CASCADE, default=None)

    #@models.permalink
    #def get_absolute_url(self):
    #    return reverse("model_detail", kwargs={"pk": self.pk})
    

    def has_stock(self):
        return self.amount > 0

    def __str__(self):
        return self.title

    def is_showable(self):
        return has_stock & self.title != ''

class Categoria (models.Model):
    name = models.CharField(max_length=100)

    class Meta:
        ordering = ('name',)

    def __str__(self):
        return self.name

class Cliente (models.Model):
    name = models.CharField(max_length=100)
    birth = models.DateTimeField()
    carrinho = models.ManyToManyField(Vinho)

    def __str__(self):
        return self.name

    def calcularTotalCarrinho(self):
        soma = 0
        for vin in self.carrinho.all():
            soma += vin.price
        
        print(soma)
        return soma