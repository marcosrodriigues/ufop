import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UrlService } from './default/url.service';


@Injectable({
  providedIn: 'root'
})
export class UtilService {

  private _estados: any = [
    {sigla: "AC", nome: "Acre"},
    {sigla: "AL", nome: "Alagoas"},
    {sigla: "AP", nome: "Amapá"},
    {sigla: "AM", nome: "Amazonas"},
    {sigla: "BA", nome: "Bahia"},
    {sigla: "CE", nome: "Ceará"},
    {sigla: "DF", nome: "Distrito Federal"},
    {sigla: "ES", nome: "Espírito Santo"},
    {sigla: "GO", nome: "Goiás"},
    {sigla: "MA", nome: "Maranhão"},
    {sigla: "MT", nome: "Mato Grosso"},
    {sigla: "MS", nome: "Mato Grosso do Sul"},
    {sigla: "MG", nome: "Minas Gerais"},
    {sigla: "PA", nome: "Pará"},
    {sigla: "PB", nome: "Paraíba"},
    {sigla: "PR", nome: "Paraná"},
    {sigla: "PE", nome: "Pernambuco"},
    {sigla: "PI", nome: "Piauí"},
    {sigla: "RJ", nome: "Rio de Janeiro"},
    {sigla: "RN", nome: "Rio Grande do Norte"},
    {sigla: "RS", nome: "Rio Grande do Sul"},
    {sigla: "RO", nome: "Rondônia"},
    {sigla: "RR", nome: "Roraima"},
    {sigla: "SC", nome: "Santa Catarina"},
    {sigla: "SP", nome: "São Paulo"},
    {sigla: "SE", nome: "Sergipe"},
    {sigla: "TO", nome: "Tocantins"}
  ]

  constructor(private _http : HttpClient, private _url : UrlService) { }

  private baseUtil =  this._url.baseUrl() + "/util";

  getAddressByCep(cep) {
    cep = cep.replace("-", "");
    return this._http.get(`https://viacep.com.br/ws/${cep}/json/`);
  }

  getEstadosBrasileiros() {
    return this._estados;
  }

  getUfWhereHasRepublic() {
    return this._http.get(this.baseUtil + "/getUfWhereHasRepublic");
  }

  getCidadesByEstado(uf: string) {
    return this._http.get(this.baseUtil + "/getCidadeByEstado/" + uf);
  }

  getCityWhereHasRepublic(uf: string) {
    return this._http.get(this.baseUtil + "/getCityWhereHasRepublic/" + uf);
  }
}
