# Generated by Django 2.2.2 on 2019-06-15 01:25

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('vinhos', '0005_remove_vinho_category'),
    ]

    operations = [
        migrations.DeleteModel(
            name='Categoria',
        ),
    ]
