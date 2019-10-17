import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { RepublicaService } from 'src/app/service/republica.service';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit {

  cidade = '';
  reps: any = [];
  me : any = {};

  constructor(private router: ActivatedRoute, 
              private _repService : RepublicaService,
              private _userService : UserService) { 
    this.router.queryParams.subscribe(params => {
      this.cidade = params['q'];
    })
  }

  ngOnInit() {
      this.loadMe();
      this.loadReps();
  }

  loadMe() {
    this._userService.me().subscribe((data: any) => {
      this.me = data.perfil.personalidade;
    })
  }

  loadReps() {
    this._repService.findByCity(this.cidade).subscribe(data => {
      this.reps = data;
    }, err => {
      alert(err.error.message);
    });
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }

  calculaPorcentagem(rep, me) {
    if (rep.distanciaGeral >= this.sumPersonalidade(me))
      return Math.round((1 - this.sumPersonalidade(me) / rep.distanciaGeral) * 100);

    return Math.round((1 - rep.distanciaGeral / this.sumPersonalidade(me)) * 100);
  }
}
