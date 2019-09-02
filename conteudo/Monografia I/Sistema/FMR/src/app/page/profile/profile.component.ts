import { Component, OnInit } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { UserService } from 'src/app/service/user.service';
import { UtilService } from 'src/app/service/util.service';
import { UniversidadeService } from 'src/app/service/universidade.service';



//import * as $ from 'jquery';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit {

  profile: any = { }
  personalidade: any = {
    abertura: 0,
    concordancia: 0,
    consciencia: 0,
    extroversao: 0,
    neuroticismo: 0
   }
  endereco: any = { }
  newUniversidade: any = { }
  universidades: any = [];
  
  profUniversidade: number = 0;
  estados: any = [];

  dataChart = [
    { y: 0.1, name: "Abertura para o Novo" },
    { y: 0.1, name: "Concordância" },
    { y: 0.1, name: "Consciência" },
    { y: 0.1, name: "Extroversão" },
    { y: 0.1, name: "Neuroticismo" },
  ];

  constructor(private _userService : UserService,
              private _utilService : UtilService,
              private _universidadeService : UniversidadeService) { }

  ngOnInit() {
    this._userService.checkCredentials();
    this.initEstados();
    this.initUniversidades();
    this.initMe();
  }

  initEstados() {
    this.estados = this._utilService.getEstadosBrasileiros();
  }

  initMe() {
    this._userService.me().subscribe(data => {
      this.profile = data;
      
      if (this.profile.universidade != null) this.profUniversidade = this.profile.universidade.id;

      if (this.profile.endereco != null) this.endereco = this.profile.endereco;
      
      if (this.profile.perfil.personalidade != null) {
        this.personalidade = this.profile.perfil.personalidade;
        this.dataChart[0].y = this.personalidade.abertura;
        this.dataChart[1].y = this.personalidade.concordancia;
        this.dataChart[2].y = this.personalidade.consciencia;
        this.dataChart[3].y = this.personalidade.extroversao;
        this.dataChart[4].y = this.personalidade.neuroticismo;
      }
      
      this.initializeChart('chart');
    }, err => {
      //console.log(err);
    });
  }
  initUniversidades() {
    this._universidadeService.getAll().subscribe(data => {
      this.universidades = data;
      console.log(this.universidades);
    });
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
    if (this.endereco != undefined) {
      this.profile.endereco = this.endereco;
    }


    
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
      exportEnabled: true,
      title:{
        text: "Personalidade"
      },
      data: [{
        type: "pie",
        showInLegend: true,
        toolTipContent: "<b>{name}</b>: {y} (#percent%)",
        indexLabel: "{name} - #percent%",
        dataPoints: this.dataChart,
      }]
    });
    chart.render();
  }

  addUniversidade() {
    this._universidadeService.save(this.newUniversidade).subscribe((data: any) => {
      this.profUniversidade = data.id;
      this.profile.universidade = data;
      this.universidades.push(data);
      alert('Universidade salva!');
      this.newUniversidade = {};
    });
  }

  changeUniversidade() {
    this.universidades.forEach(uni => {
      if (uni.id == this.profUniversidade) {
        this.profile.universidade = uni;
        return;
      }
    });
  }

  compareUniversidade(opt1, opt2)  {
    console.log("Here i'm ");
    console.log(opt1);
    console.log(opt2);
    if (opt1 != undefined && opt2 != undefined) return opt1.id == opt2.id;
    return opt1 == opt2;
  }
}
