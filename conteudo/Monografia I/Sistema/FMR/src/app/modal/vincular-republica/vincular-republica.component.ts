import { Component, OnInit, Input, OnChanges } from '@angular/core';
import { UtilService } from 'src/app/service/util.service';
import { RepublicaService } from 'src/app/service/republica.service';
import { EstudanteService } from 'src/app/service/estudante.service';

@Component({
  selector: 'app-vincular-republica',
  templateUrl: './vincular-republica.component.html',
  styleUrls: ['./vincular-republica.component.css']
})
export class VincularRepublicaComponent implements OnInit, OnChanges {

  @Input('user') profile: any = { };

  _estados: any = [];
  filterEstado: string = "";

  _cidades: any = [];
  filterCidade: string = "";

  _republicas: any = [];
  republica: number;

  constructor(private _utilService: UtilService,
              private _republicaService: RepublicaService,
              private _estudanteService: EstudanteService) { }

  ngOnChanges() {
    this.initFields();
  }

  private initFields() {
    if (this.profile.endereco != undefined && this.profile.endereco.uf != null) {
      this.filterEstado = this.profile.endereco.uf;
      this.changeEstado();
    }
      
    if (this.profile.endereco != undefined && this.profile.endereco.cidade != null) {
      this.filterCidade = this.profile.endereco.cidade;
      this.changeCidade();
    }
      
  }

  ngOnInit() {
    this.initEstados();
  }

  private initEstados() {
    this._estados = this._utilService.getEstadosBrasileiros();

    this._utilService.getUfWhereHasRepublic().subscribe((data: any[]) => {
        let stateShow = [];

        this._estados.forEach(uf => {
          if (data.indexOf(uf.sigla) >= 0) {
            stateShow.push(uf);
          } 
        });
    })
  }

  changeEstado() {
    this._utilService.getCityWhereHasRepublic(this.filterEstado).subscribe(data => {
      this._cidades = data;
    })
  }

  changeCidade() {
    this._republicaService.findByUfAndCity(this.filterEstado, this.filterCidade).subscribe(data => {
        this._republicas = data;
    });
  }

  changeRepublica() {
    console.log(this.republica);
  }

  solicitarVinculo() {
      this._estudanteService.solicitarVinculo(this.republica).subscribe(data => {
        alert('Sua requisição foi solicitada para a república');
      })
  }
}
