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
  republica: number = 0;

  constructor(private _utilService: UtilService,
              private _republicaService: RepublicaService,
              private _estudanteService: EstudanteService) { }

  msgVinculo = "";
  classMsg = "danger";
  ngOnChanges() {
    this.initEstados();
  }

  private initFields() {
    if(this.profile.endereco != undefined) {
      if (this.profile.endereco.uf != null) {
        this.filterEstado = this.profile.endereco.uf;
        this.changeEstado();
      }

      if (this.profile.endereco.uf != null) {
        this.filterCidade = this.profile.endereco.cidade;
        this.changeCidade();
      }
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

        this._estados = stateShow;

        this.initFields();
    })
  }

  changeEstado() {
    this._utilService.getCityWhereHasRepublic(this.filterEstado).subscribe(data => {
      this._cidades = data;
    })
  }

  changeCidade() {
    this.filterCidade;
    this._republicaService.findByUfAndCity(this.filterEstado, this.filterCidade).subscribe(data => {
        this._republicas = data;
    });
  }

  loading = false;
  solicitarVinculo() {
    this.loading = true;
    this._estudanteService.solicitarVinculo(this.republica).subscribe(data => {
      this.msgVinculo = "Sua solicitação foi enviada para a república.";
      this.classMsg = "success";
      this.loading = false;
      window.location.href = window.location.pathname;
    }, err => {
      this.msgVinculo = "Ocorreu um erro. Tente novamente e caso o problema persista, entre em contato com o administrador do sistema.";
      this.classMsg = "danger";
      this.loading = false;
    })
  }

  compareFn(c1: any, c2:any): boolean {     
    return c1 && c2 ? c1.id === c2.id : c1 === c2; 
  }

  compareFnTxt(c1: any, c2:any): boolean {  
    let equal = c1.toLowerCase() === c2.toLowerCase();
    if (equal) this.filterCidade = c1;
    return equal; 
  }
}
