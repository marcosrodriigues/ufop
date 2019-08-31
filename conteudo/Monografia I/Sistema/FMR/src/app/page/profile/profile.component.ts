import { Component, OnInit } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { UserService } from 'src/app/service/user.service';
import { PersonalidadeService } from 'src/app/service/personalidade.service';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit {

  profile: any = {
    endereco: {
      
    }
  }

  dataChart = [
    { y: 0.1, name: "Abertura para o Novo" },
    { y: 0.1, name: "Concordância" },
    { y: 0.1, name: "Consciência" },
    { y: 0.1, name: "Extroversão" },
    { y: 0.1, name: "Neuroticismo" },
  ];

  constructor(private _userService : UserService,
              private _personalidadeService : PersonalidadeService) { }

  ngOnInit() {
    this.initializeChart('chart');

    this._userService.checkCredentials();
    this._userService.me().subscribe(data => {
      this.profile = data;
      
      let personalidade: any = this.profile.perfil.personalidade;
      if (personalidade != null) {
        this.dataChart[0].y = personalidade.abertura;
        this.dataChart[1].y = personalidade.concordancia;
        this.dataChart[2].y = personalidade.consciencia;
        this.dataChart[3].y = personalidade.extroversao;
        this.dataChart[4].y = personalidade.neuroticismo;
      }
      
      this.initializeChart('chart');
    }, err => {
      //console.log(err);
    })

    // this._personalidadeService.getPersonalidade().subscribe(data => {
    //   console.log(data);
    // })
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

}
