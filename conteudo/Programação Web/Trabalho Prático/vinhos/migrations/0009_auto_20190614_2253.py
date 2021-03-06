# Generated by Django 2.2.2 on 2019-06-15 01:53

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('vinhos', '0008_remove_vinho_category'),
    ]

    operations = [
        migrations.CreateModel(
            name='Categoria',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
            ],
        ),
        migrations.AlterField(
            model_name='vinho',
            name='picture',
            field=models.ImageField(upload_to='vinhos_imagens', verbose_name='Imagem: '),
        ),
        migrations.AddField(
            model_name='vinho',
            name='categoria',
            field=models.ForeignKey(default=None, on_delete=django.db.models.deletion.CASCADE, related_name='vinhos', to='vinhos.Categoria'),
        ),
    ]
