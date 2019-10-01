import { Component, OnInit, Input, OnChanges } from '@angular/core';
import { UserService } from 'src/app/service/user.service';
import { UtilService } from 'src/app/service/util.service';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { FileService } from 'src/app/service/file.service';
import { RepublicaService } from 'src/app/service/republica.service';

@Component({
  selector: 'app-profile-republica',
  templateUrl: './profile-republica.component.html',
  styleUrls: ['./profile-republica.component.css']
})
export class ProfileRepublicaComponent implements OnInit, OnChanges {

  @Input("profile") profile : any = { }

  personalidade: any = {
    abertura: 0,
    concordancia: 0,
    consciencia: 0,
    extroversao: 0,
    neuroticismo: 0
   }
   
   endereco: any = { }
   estados: any = [ ]
   fotoPerfil: File;

   dataChart = [
    { y: 0.1, name: "Abertura para o Novo" },
    { y: 0.1, name: "Concordância" },
    { y: 0.1, name: "Consciência" },
    { y: 0.1, name: "Extroversão" },
    { y: 0.1, name: "Neuroticismo" },
  ];

  constructor(private _userService: UserService,
              private _utilService : UtilService,
              private _fileService : FileService,
              private _repService : RepublicaService) { }

  ngOnInit() {
    this._userService.checkCredentials();
    this.initEstados();
  }

  ngOnChanges() {
    this.configureMe();
    this.initializeChart('chart');
  }

  initEstados() {
    this.estados = this._utilService.getEstadosBrasileiros();
  }

  configureMe() {
    if (this.profile.endereco != null)  this.endereco = this.profile.endereco;
    
    if (this.profile.perfil != null)
      if (this.profile.perfil.personalidade != null) {
        this.personalidade = this.profile.perfil.personalidade;
        this.dataChart[0].y = this.personalidade.abertura;
        this.dataChart[1].y = this.personalidade.concordancia;
        this.dataChart[2].y = this.personalidade.consciencia;
        this.dataChart[3].y = this.personalidade.extroversao;
        this.dataChart[4].y = this.personalidade.neuroticismo;
      }
  }

  changeCep() {
    this._utilService.getAddressByCep(this.endereco.cep).subscribe((data : any) => {
      if (data != null) {
        this.endereco.logradouro = data.logradouro;
        this.endereco.complemento = data.complemento;
        this.endereco.bairro = data.bairro;
        this.endereco.uf = data.uf;
        this.endereco.cidade = data.localidade;
      }
    }, err => {
      alert("CEP inválido!");
    })
  }

  save() {
    if (this.endereco != undefined) this.profile.endereco = this.endereco;
    
    this._userService.update(this.profile).subscribe(data => {
      alert("Usuário atualizado");
      this.profile = data;
      this.endereco = this.profile.endereco;
    })
  }
  
  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: false,
      title:{
        text: "Personalidade"
      },
      data: [{
        type: "column",
        showInLegend: false,
        toolTipContent: "<b>{name}</b>: {y}",
        indexLabel: "{name}",
        dataPoints: this.dataChart,
      }]
    });
    chart.render();
  }

  upload(event) {
    if (event.target.files.length > 0) {
      let foto = event.target.files[0];
      this._fileService.upload(foto).subscribe((data:any) => {
        this.profile.fotoUrl = data.fileUri;
      })
    }
  }

  calcularPersonalidade() {
    this._repService.calcularPersonalidade(this.profile).subscribe(data => {
      console.log(data);
    })
  }
}
